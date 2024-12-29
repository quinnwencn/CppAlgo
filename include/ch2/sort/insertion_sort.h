#pragma once

#include <vector>
#include <cstdint>

namespace Algo {

class InsertionSort {
public:
    static void Sort(std::vector<int>& arr) {
        if (arr.empty()) {
            return;
        }

        auto size = arr.size();
        for (uint32_t i = 1; i < size; i++) {
            for (uint32_t j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
};

}