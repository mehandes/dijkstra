cmake_minimum_required(VERSION 3.16)
project(dijkstra LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 11)

include_directories("src")

# Source

add_library(wgraph src/wgraph.c src/wgraph.h)


# Tests

option(ENABLE_TESTS "Enable testing" ON)
if (ENABLE_TESTS)

  enable_testing()
  include(GoogleTest)
  add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

  add_executable(dijkstra_test test/dijkstra_test.cc)
  target_link_libraries(dijkstra_test gtest_main gtest)
  gtest_discover_tests(dijkstra_test)
  add_test(dijkstra dijkstra_test)

  add_executable(pqueue_test test/pqueue_test.cc)
  target_link_libraries(pqueue_test gtest_main gtest)
  gtest_discover_tests(pqueue_test)
  add_test(pqueue pqueue_test)

  add_executable(wgraph_test test/wgraph_test.cc)
  target_link_libraries(wgraph_test wgraph gtest_main gtest)
  gtest_discover_tests(wgraph_test)
  add_test(wgraph wgraph_test)

endif()