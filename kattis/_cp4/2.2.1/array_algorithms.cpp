#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<int> arr) {
    for (auto a: arr) cout << a << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {2,3,54,1,3,4};
    // binary search using lower bound
    sort(arr.begin(), arr.end());
    print(arr);
    auto pos = lower_bound(arr.begin(), arr.end(), 4);
    cout << "lower bound at position " << pos-arr.begin() << endl;
    auto pos2 = lower_bound(arr.begin(), arr.end(), 4);
    cout << "upper bound at position " << pos2 - arr.begin() << endl;
    
}