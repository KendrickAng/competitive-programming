#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int p; cin >> p;
    while(p--) {
        int k; cin >> k;
        int ans = 0;

        // fill array
        int arr[12];
        for (int i = 0; i < 12; i++) {
            cin >> arr[i];
        }

        // form subsets
        for (int i = 1; i < (1 << 12); i++) {
            vector<int> seq;
            int prev = -1;
            bool isOk = true;
            for (int j = 0; j < 12; j++) {
                if (i & (1 << j)) { // member of current subset
                    if (j == 0 || j == 11) { // contains number on edge, throw away
                        isOk = false; break;
                    }
                    if (prev != -1 && abs(prev - j) != 1) { // not contiguous sequence
                        isOk = false; break;
                    }
                    prev = j;
                    seq.push_back(j);
                }
            }
            
            // check
            if (isOk && seq.size() >= 1) {
                bool isCorrect = true;
                int leftIdx = seq[0];
                int rightIdx = seq[seq.size()-1];
                int left = arr[leftIdx-1];
                int right = arr[rightIdx+1];
                for (int k = leftIdx; k <= rightIdx; k++) {
                    if (arr[k] <= left || arr[k] <= right) {
                        isCorrect = false;
                        break;
                    }
                }
                if (isCorrect) ans++;
            }
        }

        cout << k << " " << ans << endl;
    }
}