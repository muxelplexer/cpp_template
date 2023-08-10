add_executable(project 
    src/main.cpp
)
target_compile_features(project PRIVATE cxx_std_23)
target_include_directories(project PRIVATE inc/)
