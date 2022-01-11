#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

bool isValid(string &a, string &b, string &c, int i) {
    return (a[i] == b[i] && a[i] == c[i] && b[i] == c[i]) || (a[i] != b[i] && a[i] != c[i] && b[i] != c[i]);
}

bool isValid(string &a, string &b, string &c) {
    for (int i = 0; i < 4; i++) {
        if (!isValid(a,b,c,i)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<string> cards;
    for (int i = 0; i < 12; i++) {
        string tmp; cin >> tmp;
        cards.push_back(tmp);
    }

    // find all sets
    vector<tuple<int,int,int>> sets;
    for (int i = 0; i < cards.size(); i++) {
        for (int j = i+1; j < cards.size(); j++) {
            for (int k = j+1; k < cards.size(); k++) {
                string a, b, c, d;
                a = cards[i]; b = cards[j]; c = cards[k];
                if (isValid(a,b,c)) {
                    int arr[3] = {i,j,k};
                    sort(arr, arr+3);
                    sets.push_back({arr[0], arr[1], arr[2]});
                }
            }
        }
    }
    sort(sets.begin(), sets.end());
    
    if (sets.size() > 0) {
        for (auto &tup: sets) {
            cout << get<0>(tup)+1 << " " << get<1>(tup)+1 << " " << get<2>(tup)+1 << endl;
        }
    } else {
        cout << "no sets" << endl;
    }
}