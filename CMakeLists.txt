cmake_minimum_required(VERSION 3.29)

project(project
   VERSION 0.0.1
)

add_executable(project
    src/main.cpp
)

target_compile_features(project PRIVATE 
   cxx_std_23
   c_std_23
)

set_target_properties(project PROPERTIES
   CXX_EXTENSIONS FALSE
   INTERPROCEDURAL_OPTIMIZATION TRUE
)

target_include_directories(project PRIVATE inc/)

#find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
#set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}")
#set_target_properties(project PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")

target_compile_options(project PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Weffc++ -Wconversion -Wsign-conversion -fms-extensions
)


