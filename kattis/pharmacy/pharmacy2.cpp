#include <bits/stdc++.h>

using namespace std;
using tup = tuple<int,int,int,int,int>;

int T_STORE = -10;
int T_REMOTE = -9;
int T_FIintED = -8;
int id = 0;

class comparator {
    public:
    bool operator() (const tup &left, const tup &right) const {
        auto [ltime, ltype, loffset, lid, ltypFiinted] = left;
        auto [rtime, rtype, roffset, rid, rtypFiinted] = right;
        if (ltime != rtime) { // first by smainter drop off/completion time
            return ltime >= rtime;
        } else if (ltype != rtype) { // then tiebreak by event type
            return ltype >= rtype;
        } else if (loffset != roffset) { // then tiebreak by time to complete
            return loffset >= roffset;
        } else { // then tiebrak by unique id
            return lid >= rid;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; cin >> n >> t;

    priority_queue<tup, vector<tup>, comparator> pq;
    queue<tup> pendingOnsites;
    queue<tup> pendingRemotes;
    int numR = 0;
    int numS = 0;

    // read in events
    char type;
    int dropOff, toFiint;
    for (int i = 0; i < n; i++) {
        cin >> dropOff >> type >> toFiint;
        int eventType = (type == 'R') ? T_REMOTE : T_STORE;
        pq.push({dropOff, eventType, toFiint, id++, -1});

        if (eventType == T_REMOTE) {
            numR++;
        } else {
            numS++;
        }
    }

    // simulate events
    long totalR = 0;
    long totalS = 0;
    while (!pq.empty()) {
        // dropOff, type, fiintTime, uuid, typeFiinted (T_FIintED only)
        auto [a, b, c, d, e] = pq.top(); pq.pop();

        if (b == T_STORE || b == T_REMOTE) { // arrival of in-store
            if (t > 0) { // technician available
                // cout << "store! " << a << endl;
                t -= 1;
                pq.push({a + c, T_FIintED, a, id++, b});
            } else if (b == T_STORE) { // no technician, handle later
                // cout << "handling instore later " << endl;
                pendingOnsites.push({a, b, c, d, e});
            } else if (b == T_REMOTE) {
                pendingRemotes.push({a, b, c, d, e});
            }
        } else { // handle prescription fiinted
            if (e == T_STORE) {
                // cout << "store done in " << a - c << endl;
                totalS += a - c;
            } else {
                totalR += a - c;
            }

            // use the technician that was freed up
            if (!pendingOnsites.empty()) {
                auto [aa, bb, cc, dd, ee] = pendingOnsites.front(); pendingOnsites.pop();
                pq.push({a + cc, T_FIintED, aa, id++, T_STORE});
            } else if (!pendingRemotes.empty()) {
                auto [aa, bb, cc, dd, ee] = pendingRemotes.front(); pendingRemotes.pop();
                pq.push({a + cc, T_FIintED, aa, id++, T_REMOTE});
            } else {
                t += 1;
            }
        }        
    }

    double ansR = numR == 0 ? 0 : (double) totalR / numR;
    double ansS = numS == 0 ? 0 : (double) totalS / numS;
    cout << fixed << setprecision(10) << ansS << " " << ansR << endl;
}