#include "stddraw.h"

int main(int argc, char** argv) {
    std::vector<int> arr {1, 2, 3, 4, 2, 5};
    Algo::DrawBarChart(arr, {3, 4}, 2);

    return 0;
}