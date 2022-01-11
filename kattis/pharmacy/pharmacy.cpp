#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    priority_queue<ii, vector<ii>, greater<ii>> remotes; // min pqs
    priority_queue<ii, vector<ii>, greater<ii>> instores;
    priority_queue<int, vector<int>, greater<int>> techs;

    // add technicians
    for (int i = 0; i < k; i++) {
        techs.push(-1);
    }

    // read in visits
    int numR = 0;
    int numS = 0;
    int dropOff, fillTime;
    char type;
    for (int i = 0; i < n; i++) {
        cin >> dropOff >> type >> fillTime;
        if (type == 'R') {
            numR++;
            remotes.emplace(dropOff, fillTime);
        } else {
            numS++;
            instores.emplace(dropOff, fillTime);
        }
    }

    long totalR = 0;
    long totalS = 0;
    while (!(remotes.empty() && instores.empty())) {
        // match technicians to remotes and stores
        int tech = techs.top(); techs.pop();
        auto [rStart, rTime] = remotes.empty() ? make_pair(INF,INF) : remotes.top();
        auto [sStart, sTime] = instores.empty() ? make_pair(INF,INF) : instores.top();

        // cout << "tech: " << tech << " | s: " << sStart << " | r: " << rStart << endl;
        if (tech < rStart && tech < sStart) {
            tech = min(rStart, sStart);
        }

        if (tech >= sStart) {
            // fill s over r
            instores.pop();
            int startTime = max(tech, sStart);
            // cout << "S " << sStart << " " << sTime << " next tech: " << startTime + sTime << endl;
            techs.push(startTime + sTime);
            totalS += startTime + sTime - sStart;
        } else {
            remotes.pop();
            int startTime = max(tech, rStart);
            techs.push(startTime + rTime);
            totalR += startTime + rTime - rStart;
            // cout << "R " << rStart << " " << rTime << " next tech: " << startTime + rTime <<  endl;
        }
    }

    double ansR = numR == 0 ? 0 : (double) totalR / numR;
    double ansS = numS == 0 ? 0 : (double) totalS / numS;

    cout << fixed << setprecision(10) << ansS << " " << ansR << endl;
}