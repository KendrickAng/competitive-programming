#include <bits/stdc++.h>

using namespace std;

#define var(x) {cout << #x << " = " << x << " " << endl;}
#define LSOne ((S) & -(S))

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<string> answers(n);
    for (int i = 0; i < n; i++) {
        cin >> answers[i];
    }

    int bestScore = -1;
    // go through all answer keys
    for (int bs = 0; bs < (1 << k); bs++) {
        int classScore = INF;

        // go through all students
        for (int i = 0; i < n; i++) {
            // go through one student's answer
            int stuScore = 0;
            string &answer = answers[i];
            for (int j = 0; j < k; j++) {
                char ansKey = (bs & (1 << j)) ? 'T' : 'F';
                if (answer[k-j-1] == ansKey) {
                    stuScore++;
                }
            }

            classScore = min(classScore, stuScore);
        }

        bestScore = max(bestScore, classScore);
    }

    cout << bestScore << endl;
}
