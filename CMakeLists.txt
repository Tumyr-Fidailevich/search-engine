cmake_minimum_required(VERSION 3.22)
project(search-engine)

option(BUILD_TESTS OFF)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES src/converter_json.cpp)
set(HEADERS include/converter_json.h)

set(BOOST_INCLUDE_LIBRARIES thread filesystem system)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  Boost
  URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.7z
  USES_TERMINAL_DOWNLOAD TRUE 
  GIT_PROGRESS TRUE   
  DOWNLOAD_NO_EXTRACT FALSE
)
FetchContent_MakeAvailable(Boost)

FetchContent_Declare(
  googletest
  URL
  https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FetchContent_MakeAvailable(googletest)

add_library(search-engine-lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(search-engine-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(search-engine src/main.cpp)
target_link_libraries(search-engine PRIVATE search-engine-lib nlohmann_json::nlohmann_json Boost::filesystem)

if(BUILD_TESTS)
  # enable_testing()
  add_executable(test test/main.cpp)
  target_link_libraries(test PRIVATE search-engine-lib nlohmann_json::nlohmann_json Boost::filesystem gtest_main)
  include(GoogleTest)
  gtest_discover_tests(test)
endif() # BUILD_TESTS