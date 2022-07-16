cmake_minimum_required(VERSION "3.18.3")
set(CMAKE_CXX_STANDARD 20)
project(ptest)

add_subdirectory(rocksdb)
add_subdirectory(spdlog)

add_executable(test main.cxx)

include_directories("./rocksdb/include")
include_directories("./spdlog/include")

target_link_libraries(test PUBLIC rocksdb spdlog pthread numa ibverbs rdmacm)
#install(FILES "main.cpp" DESTINATION src)
