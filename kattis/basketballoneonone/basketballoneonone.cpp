#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    int a_pts = 0;
    int b_pts = 0;
    bool sudden_death = false;
    char winner;
    for (int i = 0; i < s.length(); i += 2) {
        char scores = s[i];
        int pts = s[i+1] - '0';
        if (scores == 'A') a_pts += pts;
        if (scores == 'B') b_pts += pts;
        if (sudden_death) {
            if (a_pts > b_pts && (a_pts-b_pts) >= 2) {
                winner = 'A';
                break;
            }
            if (b_pts > a_pts && (b_pts-a_pts) >= 2) {
                winner = 'B';
                break;
            }
        } else if (a_pts == 10 && b_pts == 10) {
            sudden_death = true;
        } else if (a_pts >= 11) {
            winner = 'A';
            break;
        } else if (b_pts >= 11) {
            winner = 'B';
            break;
        }
    }   
    std::cout << winner << std::endl;
}