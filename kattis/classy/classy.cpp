#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

const string SEP = "==============================";

struct Person {
    string name;
    vector<string> rank;
};

bool cmp(const Person& a, const Person& b) {
    vector<string> aRank = a.rank;
    vector<string> bRank = b.rank;
    for (int i = 0; i < aRank.size(); i++) {
        if (aRank[i] != bRank[i]) {
            if (aRank[i] == "upper") {
                return true;
            }
            else if (aRank[i] == "middle") {
                return (bRank[i] != "upper");
            }
            else if (aRank[i] == "lower") {
                return false;
            }
        }
    }
    return lexicographical_compare(a.name.begin(), a.name.end(), b.name.begin(), b.name.end());
}

int main() {
    string tmp;
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;
        getline(cin, tmp);
        vector<Person> arr{};

        // read in data
        for (int i = 0; i < n; i++) {
            string line, name, rank, token;
            vector<string> tokens{};
            vector<string> rrank{};
            getline(cin, line);
            istringstream ss(line);
            while (getline(ss, token, ' ')) {
                tokens.push_back(token);
            }
            name = tokens[0];
            rank = tokens[1];
            name.pop_back();
            istringstream ss2(rank);
            while (getline(ss2, token, '-')) {
                rrank.push_back(token);
            }
            reverse(rrank.begin(), rrank.end());
            arr.push_back(Person{ name, rrank });
        }

        // make all rank the same length by appending "middle"
        for (auto &a: arr) {
            int s = a.rank.size();
            if (a.rank.size() < 10) {
                for (int j = 0; j < 10-s; j++) {
                    a.rank.push_back("middle");
                }
            }
        }

        // sort, highest rank first
        sort(arr.begin(), arr.end(), cmp);
        for (auto &a: arr) {
            cout << a.name << endl;
        }

        cout << SEP << endl;
    }
}