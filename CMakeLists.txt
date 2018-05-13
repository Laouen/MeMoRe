cmake_minimum_required(VERSION 3.8)
project(MeMoRe)

# The version number.
set (MeMoRe_VERSION_MAJOR 0)
set (MeMoRe_VERSION_MINOR 0)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wl,-rpath,/usr/local/lib")

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(/usr/local/include/mongocxx/v_noabi)
include_directories(/usr/local/include/bsoncxx/v_noabi)
include_directories(/usr/local/include/libmongoc-1.0)
include_directories(/usr/local/include/libbson-1.0)
include_directories(/usr/local/lib)


find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(include ${Boost_INCLUDE_DIRS})

set(TEST_SOURCES src/recorder.cpp)

enable_testing()
FILE(GLOB TestSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*_test.cpp)
foreach(testSrc ${TestSources})
    get_filename_component(testName ${testSrc} NAME_WE)
    add_executable(${testName} test/main-test.cpp ${testSrc} ${TEST_SOURCES})
    target_link_libraries(${testName} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
    add_test(${testName} ${testName})
endforeach(testSrc)