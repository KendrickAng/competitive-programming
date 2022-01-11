#include <iostream>

int main() {
    int gold, silver, copper;
    std::cin >> gold >> silver >> copper;
    int points = 3 * gold + 2 * silver + 1 * copper;
    std::string v_card = "", t_card = "";
    if (points >= 8) {
        v_card = "Province";
    } else if (points >= 5) {
        v_card = "Duchy";
    } else if (points >= 2) {
        v_card = "Estate";
    }
    if (points >= 6) {
        t_card = "Gold";
    } else if (points >= 3) {
        t_card = "Silver";
    } else if (points >= 0) {
        t_card = "Copper";
    }

    if (v_card.length() > 0 && t_card.length() > 0) {
        std::cout << v_card << " or " << t_card;
    } else if (v_card.length() > 0) {
        std::cout << v_card << std::endl;
    } else {
        std::cout << t_card << std::endl;
    }
}