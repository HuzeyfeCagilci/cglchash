cmake_minimum_required(VERSION 3.0.0)
project(mat VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

add_library(my SHARED src/my.cpp)
add_executable(cglc src/main.cpp)

add_executable(mtest1 test/mtest1.cpp)
add_executable(mtest2 test/mtest2.cpp)

target_include_directories(mtest1 PUBLIC "src")
target_include_directories(mtest2 PUBLIC "src")

target_link_libraries(cglc PUBLIC my)
target_link_libraries(mtest1 PUBLIC my)
target_link_libraries(mtest2 PUBLIC my)

add_test("-f" cglc.exe -f sample3.txt)
add_test("-rf" cglc.exe -rf sample3.txt)
add_test("-fl" cglc.exe -rf sample3.txt)
add_test("-c" cglc.exe -c sample3.txt sample3.txt.mhs)
add_test(mtest2 mtest2.exe)
add_test(mtest1 mtest1.exe)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
