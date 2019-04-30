add_executable(rationals src/main.cpp src/rationals.cpp include/rationals.hpp)

target_include_directories(rationals PRIVATE include)

target_compile_features(rationals PRIVATE cxx_std_17)
