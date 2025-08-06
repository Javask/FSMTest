find_package(Catch2 3 REQUIRED)

add_executable("simple-fsm-tests" test.cpp)
target_link_libraries("simple-fsm-tests" Catch2::Catch2WithMain)