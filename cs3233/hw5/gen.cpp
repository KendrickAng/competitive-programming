#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MIN_T = 1;
const ll MAX_T = 10;
const ll MIN_N = 1;
const ll MAX_N = 1e5;
const ll MIN_I = 1;
const ll MAX_I = 1e5;
const ll MIN_II = 1;
const ll MAX_II = 5*1e18;
const ll MIN_ID = 1;
const ll MAX_ID = 5*1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main() {
    ll testCases = 10; // CHANGEABLE: the number of test cases output
    cout << testCases << endl;
	for (int i = 0; i < testCases; i++) {
        cout << endl;
		ll N = rand(MIN_N, MAX_N); // CHANGEABLE: number of items we currently have
        ll I = rand(MIN_I, N); // CHANGEABLE: number of items we need to maintain in usable condition
        assert(N >= MIN_N and N <= MAX_N);
        assert(I >= MIN_I and I <= MAX_I);
        assert(I <= N);
		cout << N << " " << I << endl;

        // generate items
        vector<ll> IDs;
        vector<ll> IIs;
        for (int j = 0; j < N; j++) {
            ll II = rand(MIN_II, MAX_II); // CHANGEABLE: item integrity (>= item decay)
            ll ID = rand(MIN_ID, II); // CHANGEABLE: item decay
            assert(ID >= MIN_ID and ID <= MAX_ID);
            assert(II >= MIN_II and II <= MAX_II);
            assert(ID <= II);
            IDs.push_back(ID);
            IIs.push_back(II);
        }
        // print item integrities
        for (size_t i = 0; i < IIs.size(); i++) {
            if (i != 0) cout << " ";
            cout << IIs[i];
        }
        cout << endl;
        // print item decays
        for (size_t i = 0; i < IDs.size(); i++) {
            if (i != 0) cout << " ";
            cout << IDs[i];
        }
        cout << endl;
	}
}