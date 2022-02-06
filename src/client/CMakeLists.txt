add_executable(client client.cpp  )
set(CMAKE_CXX_STANDARD 17)

target_link_libraries(client ${Boost_LIBRARIES}  )
