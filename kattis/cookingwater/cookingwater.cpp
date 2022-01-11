#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector< pair<int, int> > arr{};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[i].second < arr[j].first || arr[i].first > arr[j].second) {
                cout << "edward is right" << endl;
                return 0;
            }
        }
    }
    cout << "gunilla has a point" << endl;
}