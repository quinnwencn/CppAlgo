#include "stoptime.h"

#include <cstdlib>
#include <iostream>
#include <thread>
#include <gtest/gtest.h>

TEST(StopTime, GeneralTest) {
    using namespace std::chrono_literals;

    Algo::StopTime stoptime;
    std::this_thread::sleep_for(1000ms);
    auto seconds = stoptime.ElapseSeconds();
    auto milliseconds = stoptime.ElapseMilliseconds();
    auto microseconds = stoptime.ElapsedMicroseconds();
    auto nanoseconds = stoptime.ElapsedNanoseconds();

    // std::cout << "Cost " << seconds << " seconds." << std::endl;
    // std::cout << "Cost " << milliseconds << " milliseconds." << std::endl;
    // std::cout << "Cost " << microseconds << " microseconds." << std::endl;
    // std::cout << "Cost " << nanoseconds << " nanoseconds." << std::endl;
    
    EXPECT_TRUE(seconds > 1 && seconds < 2);
    EXPECT_EQ(static_cast<int>(milliseconds) / 1000, 1); // approximately 1
    EXPECT_EQ(static_cast<int>(microseconds) / 1000000, 1); // approximately 1
    EXPECT_EQ(static_cast<int>(nanoseconds) / 1000000000, 1); // approximately 1
}
