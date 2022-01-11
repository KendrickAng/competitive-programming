#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    int n; cin >> n;
    int arrival = 0;
    unordered_map<string, pair<int, int>> cats; // name to lvl, arrival
    map<pair<int, int>, string> catsinf; // lvl, arrival to name

    for (int i = 0; i < n; i++) {
        int cmd, lvl;
        string cat;
        cin >> cmd;
        if (cmd == 0) {
            cin >> cat >> lvl;
            pair<int, int> key = {lvl, arrival--};
            cats[cat] = key;
            catsinf[key] = cat;
        }
        else if (cmd == 1) {
            cin >> cat >> lvl;
            int oldLvl = cats[cat].first;
            int arrival = cats[cat].second;
            pair<int, int> newKey = {oldLvl + lvl, arrival};
            cats[cat] = newKey;
            catsinf[newKey] = cat;
        }
        else if (cmd == 2) {
            cin >> cat;
            cats.erase(cat);
            // lazy deletion in catsinf
        }
        else if (cmd == 3) {
            bool done = false;
            while (!done) {
                if (cats.size() == 0) {
                    cout << "The clinic is empty" << endl;
                    done = true;
                } else {
                    auto maxx = catsinf.rbegin();
                    string cat = maxx->second;
                    if (cats.find(cat) == cats.end()) {
                        catsinf.erase(maxx->first);
                    } else {
                        cout << cat << endl;
                        done = true;
                    }
                }
            }

        }
    }
}
