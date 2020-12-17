#include <chrono>

class Timer{
private:
    using clock_t = std::chrono::steady_clock::time_point;
    clock_t start;
    clock_t end;
public:
    void tic();
    void toc(); 
    double getElapsed();
    double getElapsedNanoseconds();
};
