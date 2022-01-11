#include <iostream>
#include <unordered_map>

int main() {
    int probs_solved = 0;
    int time_measure = 0;
    int time;
    std::string problem, status;
    std::unordered_map<std::string, int> attempts;
    std::cin >> time;
    while(time != -1) {
        std::cin >> problem >> status;
        
        if (status == "right") {
            // remove element
            time_measure += time;
            probs_solved++;
            attempts.erase(problem);
        } else {
            // add element + time
            time_measure += 20;
            attempts[problem] += 1;
        }

        std::cin >> time;
    }
    // deduct unsolved problems
    for (const auto& [key, val]: attempts) {
        time_measure -= 20 * val;
    }
    std::cout << probs_solved << " " << time_measure << std::endl;
}
