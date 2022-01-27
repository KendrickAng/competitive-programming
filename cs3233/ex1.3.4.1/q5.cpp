#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int,int,int>;

int main() {
    multiset<iii> birthdays;
    birthdays.emplace(5, 24, 1980);
    birthdays.emplace(5, 24, 1982);
    for (auto [mm, dd, yy]: birthdays) {
        cout << mm << " " << dd << " " << yy << endl;
    }
}

// struct Birthdate {
//     int d;
//     int m;
//     int y;
// };

// int main() {
//     vector<iii> input = {{01,01,2020},{10,10,1997}};
//     vector<Birthdate> dates;
//     for (auto [d,m,y]: input) dates.push_back({d,m,y});
//     sort(dates.begin(), dates.end(), [](Birthdate &a, Birthdate &b) {
//          if (a.d != b.d) return a.d < b.d;
//          else if (a.m != b.m) return a.m < b.m;
//          else return a.y < b.y;
//     });
//     for (auto [d,m,y]: dates) cout << d << " " << m << " " << y << endl;
// }
