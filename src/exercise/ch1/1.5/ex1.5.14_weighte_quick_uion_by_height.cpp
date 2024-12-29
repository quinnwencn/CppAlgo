#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#include "ch1/uf/uf.h" 

namespace Algo {

class WeightedQuickUnionUFByHeight: public UF {
public:
    WeightedQuickUnionUFByHeight(uint32_t N): UF(N), height_(N, 1), verbose_(true) {}
    ~WeightedQuickUnionUFByHeight() = default;

    int Root(int site) {
        if (site >= id_.size()) {
            throw std::out_of_range(std::to_string(site) + " is bigger than array's size");
        }

        while (site != id_[site]) {
            site = id_[site];
        }

        return site;
    }

    void Union(int p, int q) {
        int pRoot = Root(p);
        int qRoot = Root(q);

        if (pRoot == qRoot) {
            return;
        }

        if (height_[p] > height_[q]) {
            id_[qRoot] = pRoot;
        } else {
            id_[pRoot] = qRoot;
            height_[pRoot] = std::max(height_[pRoot], height_[qRoot] + 1);
        }

        count_--;

        if (verbose_) {
            std::cout << "Pair: " << p << "-" << q << std::endl;
            std::cout << "Index = 0 1 2 3 4 5 6 7 8 9" << std::endl;

            std::cout << "Array = ";
            for (auto i = 0; i < id_.size(); i++) {
                std::cout << id_[i] << ' ';
            }
            std::cout << std::endl;

            std::cout << "Height = ";
            for (auto i: height_) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;

            std::cout << "Site Number: " << Count() << std::endl;
            std::cout << std::endl;
        }
    }

private:
    std::vector<int> height_;
    bool verbose_;
};

}

int main(int argc, char** argv) {
    Algo::WeightedQuickUnionUFByHeight ex(10);

    ex.Union(9, 0);
    ex.Union(3, 4);
    ex.Union(5, 8);
    ex.Union(7, 2);
    ex.Union(2, 1);
    ex.Union(5, 7);
    ex.Union(0, 3);
    ex.Union(4, 2);
    ex.Union(1, 8);

    return 0;
}