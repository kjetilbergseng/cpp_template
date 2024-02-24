cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# create project
project(MyProject)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set_property(GLOBAL PROPERTY USE_FOLDERS true)

# add executable
add_executable(
    "${PROJECT_NAME}"
    "src/main.cpp"
    )

#add test project
add_executable (
    "${PROJECT_NAME}_Test" 
    "src/tests/testmain.cpp")

# add dependencies
include(cmake/CPM.cmake)
include(cmake/doctest.cmake)

CPMAddPackage(
  NAME fmt
  GITHUB_REPOSITORY fmtlib/fmt
  GIT_TAG 10.2.1
)
CPMAddPackage(
  NAME doctest
  GITHUB_REPOSITORY onqtam/doctest
  GIT_TAG 2.4.6
)
CPMAddPackage(
  NAME     spdlog
  URL      https://github.com/gabime/spdlog/archive/refs/tags/v1.12.0.zip
  URL_HASH SHA256=6174bf8885287422a6c6a0312eb8a30e8d22bcfcee7c48a6d02d1835d7769232
)
set_target_properties(fmt PROPERTIES FOLDER "dependencies")
set_target_properties(doctest_with_main PROPERTIES FOLDER "dependencies")
set_target_properties(spdlog PROPERTIES FOLDER "dependencies")

enable_testing()
doctest_discover_tests(
    "${PROJECT_NAME}_Test")

target_link_libraries(
    "${PROJECT_NAME}"
    fmt 
    spdlog)

target_link_libraries(
    "${PROJECT_NAME}_Test"
    doctest_with_main)
