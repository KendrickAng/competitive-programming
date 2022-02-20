#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define var2(x,y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define var3(x,y,z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}

void print(vector<int> &v) {
    for (int i: v) cout << i << ' '; cout << endl;
}

void printcard(vector<vector<int>> &v) {
    for (auto a: v) {
        for (auto b: a) {
            cout << b << ' ';
        }
        cout << endl;
    }
}

void solve() {
    int n; cin >> n;

    // read all cards
    vector<vector<vector<int>>> cards(n);
    for (int i = 0; i < n; i++) {
        // read one 5x5 card
        vector<vector<int>> card(5, vector<int>(5));
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                cin >> card[r][c];
            }
        }
        cards[i] = card;
    }

    // find all numbers in more than one card
    unordered_map<int, vector<tuple<int,int,int,int>>> dups;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // see if there is a matching character
            vector<vector<int>> &card1 = cards[i];
            vector<vector<int>> &card2 = cards[j];

            unordered_set<int> s1;
            unordered_map<int, int> numToRow;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    int num = card1[r][c];
                    s1.insert(num);
                    numToRow[num] = r;
                }
            }
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    int num = card2[r][c];
                    if (s1.count(num)) {
                        dups[num].push_back({i, numToRow[num], j, r});
                    }
                }
            }
        }
    }

    // for each number check if is valid answer
    set<pair<int,int>> valid;
    for (auto &[num, candidates]: dups) {
        for (auto [c1, r1, c2, r2]: candidates) {
            // regenerate potential answer
            unordered_set<int> answer;
            answer.insert(cards[c1][r1].begin(), cards[c1][r1].end());
            answer.insert(cards[c2][r2].begin(), cards[c2][r2].end());
            answer.erase(num);
            // find another card not c1 or c2 that has a row that wins earlier
            bool hasEarlierWin = false;
            for (int i = 0; i < n && !hasEarlierWin; i++) {
                if (i == c1 || i == c2) continue;
                vector<vector<int>> &card3 = cards[i];
                // try each row of the card
                for (int r = 0; r < 5 && !hasEarlierWin; r++) {
                    // is this row an earlier winner?
                    bool isWinner = true;
                    for (int c = 0; c < 5; c++) {
                        int num3 = card3[r][c];
                        isWinner = isWinner && answer.count(num3); // all numbers of row must be present
                    }
                    if (isWinner) hasEarlierWin = true;
                }
            }
            
            if (!hasEarlierWin) valid.insert({c1, c2});
        }
    }

    if (!valid.empty()) {
        auto [a, b] = *valid.begin();
        cout << a+1 << ' ' << b+1 << endl;
    } else {
        cout << "no ties" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}
