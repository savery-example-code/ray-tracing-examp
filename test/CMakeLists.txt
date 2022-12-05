# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(ray_tracing_exampTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(ray_tracing_examp_test source/ray_tracing_examp_test.cpp)
target_link_libraries(
    ray_tracing_examp_test PRIVATE
    ray_tracing_examp_lib
    Catch2::Catch2WithMain
)
target_compile_features(ray_tracing_examp_test PRIVATE cxx_std_20)

catch_discover_tests(ray_tracing_examp_test)

# ---- End-of-file commands ----

add_folders(Test)
