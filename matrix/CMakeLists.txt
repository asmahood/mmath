add_executable(matrix src/main.cpp src/matrix.cpp include/matrix.hpp include/number_trait.hpp)

target_include_directories(matrix PRIVATE include src)

target_compile_features(matrix PRIVATE cxx_std_17)
