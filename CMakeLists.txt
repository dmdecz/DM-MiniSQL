cmake_minimum_required(VERSION 3.0.0)
project(DM VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

add_executable(DM main.cpp)
add_subdirectory(compiler)
add_subdirectory(api)
add_subdirectory(catalog_manager)
add_subdirectory(buffer_manager)
add_subdirectory(common)
add_subdirectory(record_manager)

target_link_libraries(DM compiler api catalog_manager common buffer_manager record_manager)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
