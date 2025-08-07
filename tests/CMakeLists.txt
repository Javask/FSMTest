find_package(Catch2 3 REQUIRED)

add_executable("simple-fsm-tests" test.cpp)
target_link_libraries("simple-fsm-tests" Catch2::Catch2WithMain simple-fsm)
set_target_properties("simple-fsm-tests" PROPERTIES CXX_STANDARD_REQUIRED 23)