#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

namespace Algo {

void DrawBarChart(const std::vector<int>& arr, const std::vector<int>& accessIndex = {}, int target = -1) {
    int maxValue = *std::max_element(arr.begin(), arr.end());
    for (int i = maxValue; i > 0; i--) {
        for (uint8_t j = 0; j < arr.size(); j++) {
            if (arr[j] >= i) {
                if (j == target) {
                    std::cout << "\033[31m█\033[0m";
                } else if (std::find(accessIndex.begin(), accessIndex.end(), j) != accessIndex.end()) {
                    std::cout << "\033[32m█\033[0m";
                } else {
                    std::cout << "\033[38;5;240m█\033[0m";
                }
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

}
