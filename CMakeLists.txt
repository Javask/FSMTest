cmake_minimum_required(VERSION 3.10.0)

project("FSMTest" LANGUAGES CXX VERSION 0.0.1)

add_library("simple-fsm" INTERFACE)
target_include_directories("simple-fsm" INTERFACE include)
set_target_properties("simple-fsm" PROPERTIES CXX_STANDARD 23)
# target_compile_options("simple-fsm" PRIVATE -Wall -Wextra -Werror )

add_subdirectory(tests)