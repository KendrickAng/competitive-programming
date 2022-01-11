#include <iostream>
#include <iomanip>

int main() {
    int n;
    double prevTime, prevSample;
    double currTime, currSample;
    double area = 0.0;
    std::cin >> n;
    // read the starting values
    std::cin >> prevTime >> prevSample;
    for (int i = 0; i < n; i++) {
        std::cin >> currTime >> currSample;
        area += (prevSample + currSample) / 2.0 * ((currTime - prevTime) / 1000);
        prevTime = currTime;
        prevSample = currSample;
    }
    std::cout << std::setprecision(8) << area << std::endl;
}