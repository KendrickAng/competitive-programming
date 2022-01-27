#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums = {1,3,4,6,-5,-5,6,8,9};
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i: nums) cout << i << " ";
}
