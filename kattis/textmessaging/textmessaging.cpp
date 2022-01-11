#include <bits/stdc++.h>

using namespace std;

void solve(int id) {
    int maxLettersInKey, numKeys, numLetters;
    cin >> maxLettersInKey >> numKeys >> numLetters;

    priority_queue<int, vector<int>, greater<int>> keys; // min pq
    priority_queue<int, vector<int>, greater<int>> letterFreqs; // min pq

    for (int i = 0; i < numKeys; i++) {
        keys.push(0);
    }

    for (int i = 0; i < numLetters; i++) {
        int freq; cin >> freq;
        letterFreqs.push(freq);
    }

    long ans = 0;
    while (!letterFreqs.empty()) {
        int freq = letterFreqs.top();
        letterFreqs.pop();

        int key = keys.top();
        keys.pop();
        
        key += freq;
        ans += key;

        keys.push(key);
    }

    cout << "Case #" << id << ": " << ans << endl;
}

int main() {
    int id = 1;
    int t; cin >> t;
    while (t--) {
        solve(id++);
    }
}