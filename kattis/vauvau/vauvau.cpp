#include <iostream>

using namespace std;

int arr[1000];

void solve(int x) {
    if (arr[x] == 2) {
        std::cout << "both\n";
    }
    if (arr[x] == 1) {
        std::cout << "one\n";
    }
    if (arr[x] == 0) {
        std::cout << "none\n";
    }
}


int main() {
    int a, b, c, d, p, m, g;
    cin >> a >> b >> c >> d >> p >> m >> g;
    int dog1 = 0;
    bool dog1aggro = true;
    while (dog1 < 1000) {
        if (dog1aggro) {
            for (int i = dog1; i <= dog1+a; i++) {
                arr[i] += 1;
            }
            dog1 += a;
            dog1aggro = false;
        }
        else {
            dog1 += b;
            dog1aggro = true;
        }
    }
    int dog2 = 0;
    bool dog2aggro = true;
    while (dog2 < 1000) {
        if (dog2aggro) {
            for (int i = dog2; i <= dog2+c; i++) {
                arr[i] += 1;
            }
            dog2 += c;
            dog2aggro = false;
        }
        else {
            dog2 += d;
            dog2aggro = true;
        }
    }
    solve(p);
    solve(m);
    solve(g);
}