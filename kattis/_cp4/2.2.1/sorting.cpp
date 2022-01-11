#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const int a, const int b) {
    return a > b;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    sort(arr.begin(), arr.end(), cmp);
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}