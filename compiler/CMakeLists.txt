
FIND_PACKAGE(FLEX REQUIRED)
SET(FlexOutput ${CMAKE_CURRENT_SOURCE_DIR}/scanner.cpp)
SET(FlexFile ${CMAKE_CURRENT_SOURCE_DIR}/scanner.l)
# SET(FlexOutput /usr/local/opt/flex/bin/flex)
IF(FLEX_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${FlexOutput}
      COMMAND ${FLEX_EXECUTABLE}
              --outfile=${FlexOutput}
              ${FlexFile}
      COMMENT "Generating scanner.cpp"
    )
ENDIF()

FIND_PACKAGE(BISON REQUIRED)
SET(BisonOutput ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp)
SET(BisonFile ${CMAKE_CURRENT_SOURCE_DIR}/parser.y)
SET(BISON_EXECUTABLE /usr/local/bin/bison)
IF(BISON_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${BisonOutput}
      COMMAND ${BISON_EXECUTABLE}
              --xml
              --graph=parser.gv
              --defines=${CMAKE_CURRENT_SOURCE_DIR}/parser.hpp
              --output=${BisonOutput}
              ${BisonFile}
      COMMENT "Generating parser.cpp"
    )
ENDIF()

set(SRC_COMPILER ${BisonOutput} ${FlexOutput} compiler.cpp)
ADD_LIBRARY(compiler ${SRC_COMPILER})
add_subdirectory(compilertools)
add_compile_options(-Wregister)
# add_compile_definitions(-Wregister)

target_link_libraries(compiler readline compilertools)