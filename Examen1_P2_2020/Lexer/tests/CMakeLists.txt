cmake_minimum_required (VERSION 3.0)
project (test_lexer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FA2LEXER "${PROJECT_SOURCE_DIR}/../tools/fa2lexer")

# Run fa2lexer to generate the lexer
add_custom_command (
    OUTPUT lexer.h lexer.cpp
    COMMAND ${FA2LEXER} --hdr lexer.h --src lexer.cpp --tpl ${PROJECT_SOURCE_DIR}/../tools/expr_lexer.fa2l
  )

set_source_files_properties(
    ${PROJECT_SOURCE_DIR}/../expr_lexer.cpp
    PROPERTIES OBJECT_DEPENDS lexer.cpp
)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
  
add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}/../expr_lexer.cpp
                                test_lexer.cpp)

