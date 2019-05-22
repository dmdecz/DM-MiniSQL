aux_source_directory(. SRC_COMPILERTOOLS)

add_library(compilertools ${SRC_COMPILERTOOLS})

add_subdirectory(expressions)
add_subdirectory(statements)

target_link_libraries(compilertools expressions statements)