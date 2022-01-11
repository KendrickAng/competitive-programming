#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        // read values of the ruler
        int tmp;
        vector<int> ruler;
        while (ss >> tmp) {
            ruler.push_back(tmp);
        }
        sort(ruler.begin(), ruler.end());

        // check ruler
        int largest = ruler[ruler.size()-1];
        bool isRuler = true;
        unordered_set<int> marks;
        for (int i = 0; i < ruler.size(); i++) {
            for (int j = i+1; j < ruler.size(); j++) {
                int mark = ruler[j] - ruler[i];
                if (marks.count(mark)) {
                    isRuler = false;
                    break;
                } else {
                    marks.insert(mark);
                }
            }
            if (!isRuler) break;
        }

        if (isRuler && marks.size() == largest) {
            cout << "perfect" << endl;
        }
        else if (isRuler) {
            cout << "missing ";
            for (int i = 1; i <= largest; i++) {
                if (marks.find(i) == marks.end()) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
        else {
            cout << "not a ruler" << endl;
        }
    }
}