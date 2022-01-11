#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, h;
vector<int> ground, ceiling;
map<int, int> levels;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (i % 2 == 0) ground.push_back(tmp);
        else ceiling.push_back(tmp);
    }
    sort(ground.begin(), ground.end());
    sort(ceiling.begin(), ceiling.end());

    int minObs = 200001;
    for (int i = 1; i <= h; i++) {
        int obsg = ground.end() - lower_bound(ground.begin(), ground.end(), i);
        int obsc = ceiling.end() - lower_bound(ceiling.begin(), ceiling.end(), h-i+1);
        int key = obsg+obsc;
        // cout << "level " << i << " " << obsg << " " << obsc <<" "<< key << endl;
        levels[key]++;
        if (key < minObs) {
            minObs = key;
        }
    }
    cout << minObs << " " << levels[minObs] << endl;
}