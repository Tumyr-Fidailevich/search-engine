cmake_minimum_required(VERSION 3.22)
project(search-engine)

option(BUILD_TESTS OFF)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES src/converter_json.cpp src/inverted_index.cpp src/search_server.cpp src/relative_index.cpp src/config.cpp)
set(HEADERS include/converter_json.h include/inverted_index.h include/search_server.h include/relative_index.h include/config.h include/document.h)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  googletest
  URL
  https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FetchContent_MakeAvailable(googletest)

add_library(search-engine-lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(search-engine-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_precompile_headers(search-engine-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/pch.h)
target_link_libraries(search-engine-lib PUBLIC nlohmann_json::nlohmann_json)

add_executable(search-engine src/main.cpp)
target_link_libraries(search-engine PUBLIC search-engine-lib) 


if(BUILD_TESTS)
  enable_testing()
  set(TEST_SOURCES test/test.cpp test/test_converter_json.h)
  add_executable(test_search_engine ${TEST_SOURCES})
  target_link_libraries(test_search_engine PUBLIC search-engine-lib gtest_main)
  include(GoogleTest)
  gtest_discover_tests(test_search_engine)

  include(CTest)
  add_test(NAME all_tests COMMAND test_search_engine CONFIGURATION Debug)
endif() # BUILD_TESTS