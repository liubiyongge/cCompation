cmake_minimum_required(VERSION "3.18.3")
set(CMAKE_CXX_STANDARD 20)
project(ptest)

add_subdirectory(rocksdb)
add_executable(test main.cpp)
include_directories("./rocksdb/include")
target_link_libraries(test PUBLIC rocksdb)
#install(FILES "main.cpp" DESTINATION src)
