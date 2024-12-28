find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_SRCS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(test_algo main.cpp ${TEST_SRCS})
target_include_directories(test_algo PUBLIC 
    ${PROJECT_SOURCE_DIR}/include 
    ${GTest_INCLUDE_DIRS})
target_link_libraries(test_algo GTest::gtest GTest::gtest_main)