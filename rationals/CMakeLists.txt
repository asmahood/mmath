add_executable(rationals src/main.cpp src/rationals.cpp src/util.cpp src/util.hpp include/rationals.hpp)

target_include_directories(rationals PRIVATE include src)

target_compile_features(rationals PRIVATE cxx_std_17)
