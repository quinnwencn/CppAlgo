#include <cstdlib>
#include <iostream>
#include <map>
#include "ch1/uf/weighted_quick_union_uf.h"

class ErdosRenyi {
public:
    ErdosRenyi() = default;
    ~ErdosRenyi() = default;

    void Init() {
        std::cout << "Please an integer: ";
        std::cin >> N_;
    }

    int N() const {
        return N_;
    }

    std::pair<int, int> GeneratePair() const {
        int left = std::rand() % N();
        int right = std::rand() % N();
        return std::make_pair(left, right);
    }

private:
    int N_ = -1;
};

int main(int argc, char** argv) {
    ErdosRenyi client;
    client.Init();
    std::cout << "N: " << client.N() << std::endl;
    
    Algo::WeightedQuickUnionUF uf(client.N());
    while (uf.Count() != 1) {
        auto pair = client.GeneratePair();
        std::cout << "Generated pair: " << pair.first << " - " << pair.second << std::endl;
        if (uf.Connected(pair.first, pair.second)) {
            std::cout << pair.first << " - " << pair.second << " is connected." << std::endl;
        } else {
            uf.Union(pair.first, pair.second);
        }

        std::cout << std::endl;
    }

    std::cout << "All sites are connected!" << std::endl;

    return  0;
}
