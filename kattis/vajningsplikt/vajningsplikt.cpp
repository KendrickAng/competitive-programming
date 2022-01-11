#include <iostream>

std::string r(std::string dir) {
    if (dir == "North") return "East";
    if (dir == "East") return "South";
    if (dir == "South") return "West";
    if (dir == "West") return "North";
}

int main() {
    std::string arrive, leave, vehicle;
    std::cin >> arrive >> leave >> vehicle;
    // standardise everything to coming from south
    if (arrive == "North") {
        arrive = r(r(arrive));
        leave = r(r(leave));
        vehicle = r(r(vehicle));
    }
    if (arrive == "South") {
        // do nothing
    }
    if (arrive == "East") {
        arrive = r(arrive);
        leave = r(leave);
        vehicle = r(vehicle);
    }
    if (arrive == "West") {
        arrive = r(r(r(arrive)));
        leave = r(r(r(leave)));
        vehicle = r(r(r(vehicle)));
    }
    if (leave == "North" && vehicle == "East") {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    if (leave == "West" && (vehicle == "North" || vehicle == "East")) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    std::cout << "No" << std::endl;
    return 0;
}
