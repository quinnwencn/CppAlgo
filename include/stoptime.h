#pragma once
#include <chrono>

namespace Algo {

class StopTime {
public:
    StopTime() : start_(std::chrono::steady_clock::now()) {}
    ~StopTime() = default;

    double ElapseSeconds() const {
        return std::chrono::duration_cast<std::chrono::duration<double>>(ElapseTime()).count();
    }

    double ElapseMilliseconds() const {
        return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(ElapseTime()).count();
    }
    
    double ElapsedMicroseconds() const {
        return std::chrono::duration_cast<std::chrono::duration<double, std::micro>>(ElapseTime()).count();
    }

    double ElapsedNanoseconds() const {
        return std::chrono::duration_cast<std::chrono::duration<double, std::nano>>(ElapseTime()).count();
    }

private:
    std::chrono::steady_clock::duration ElapseTime() const {
        auto now = std::chrono::steady_clock::now();
        return now - start_;
    }

    std::chrono::time_point<std::chrono::steady_clock> start_;
};

}
