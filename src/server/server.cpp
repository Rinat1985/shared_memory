#include <stdlib.h>
#include <iostream>
#include <boost/interprocess/managed_windows_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <string>

int main(int argc, char *argv[]){
    using namespace boost::interprocess;
    typedef boost::interprocess::allocator<char, boost::interprocess::managed_windows_shared_memory::segment_manager> CharAllocator;
    typedef boost::interprocess::basic_string<char, std::char_traits<char>, CharAllocator> string;
    managed_windows_shared_memory shm(create_only, "MySharedMemory", 10240);
    while(1){
        std::cout << "Input something:" << std::endl;
        std::string str;
        std::cin >> str;
        string * mess = shm.find_or_construct<string>("Message")(str, shm.get_segment_manager());
        std::pair<string *, std::size_t> ret = shm.find<string>("Message");
        std::cout << *(ret.first) << std::endl;
    }

    return 0;
}
