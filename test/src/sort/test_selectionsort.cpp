#include "ch2/selection_sort.h"

#include <gtest/gtest.h>

TEST(SelectionSortTest, AlphTest) {
    std::string s {"SORTEXAMPLE"};

    Algo::SelectionSort::Sort(s);
    EXPECT_EQ("AEELMOPRSTX", s);
}

TEST(SelectionSortTest, IntArrTest) {
    std::vector<int> arr {3, 2, 1, 5, 9, 7, 0, 4, 6, 8};
    
    Algo::SelectionSort::Sort(arr);
    for (auto i = 0; i < 10; i++) {
        EXPECT_EQ(i, arr[i]);
    }
}