#pragma once

#include <vector>
#include <cstdint>

namespace Algo {

class SelectionSort {
public:
    static void Sort(std::vector<int>& arr) {
        if (arr.empty()) {
            return;
        }

        auto size = arr.size();
        for (uint32_t i = 0; i < size; i++) {
            for (uint32_t j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }
};

}