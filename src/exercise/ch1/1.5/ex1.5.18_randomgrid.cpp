#include <cstdint>
#include <vector>
#include <random>
#include <iostream>
#include <set>

class RandomGrid {
public:
    RandomGrid() = default;
    ~RandomGrid() = default;

    class Connection {
    public:
        Connection(int p, int q): p_(p), q_(q) {}
        ~Connection() = default;

        void Print() const {
            std::cout << p_ << " - " << q_ << std::endl;
        }

    private:
        int p_;
        int q_;
    };

    static std::vector<Connection> Generate(uint16_t N) {
        std::vector<Connection> temp;
        int size = N * (N - 1);
        temp.reserve(size);

        for (uint16_t i = 0; i < N; i++) {
            for (uint16_t j = 0; j < N; j++) {
                if (i != j) {
                    temp.emplace_back(i, j);
                }
            }
        }

        std::vector<Connection> result;
        result.reserve(size);
        std::set<int> visited;
        while (result.size() != size) {
            auto index = RandomInt(size);
            if (visited.find(index) != visited.end()) {
                continue;
            }

            result.push_back(temp[index]);
            visited.insert(index);
        }

        return result;
    }

private:
    static int RandomInt(int N) {
        std::random_device dev;
        std::mt19937 rng {dev()};
        std::uniform_int_distribution<int> dist{0, N};

        return dist(rng);
    }
};

int main(int argc, char** argv) {
    std::cout << "Input N:";
    int N;
    std::cin >> N;

    RandomGrid rg;
    auto arr = rg.Generate(N);
    std::cout << "Connections:" << std::endl;
    for (auto& c: arr) {
        c.Print();
    }

    return 0;
}
