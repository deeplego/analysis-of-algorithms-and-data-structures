#include "Timer.h"

void Timer::tic() { this->start = std::chrono::steady_clock::now(); }
void Timer::toc() { this->end = std::chrono::steady_clock::now(); }
double Timer::getElapsed() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
        this->end - this->start
    ).count();
}
double Timer::getElapsedNanoseconds() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
        this->end - this->start
    ).count();
}
