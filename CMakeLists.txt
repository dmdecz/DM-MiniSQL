cmake_minimum_required(VERSION 3.0.0)
project(DM VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DM main.cpp)
add_subdirectory(compiler)
add_subdirectory(api)

target_link_libraries(DM compiler api)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
