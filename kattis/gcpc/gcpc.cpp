#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

using ost = tree<tuple<int,int,int>,null_type,less<tuple<int,int,int>>,rb_tree_tag,tree_order_statistics_node_update>; 

// using ost = tree<
// tuple<int,int>, // key type
// null_type, // mapped policy
// less<tuple<int,int>>, // key comparison function
// rb_tree_tag, // specify underlying data structure to use
// tree_order_statistics_node_update>; // policy for updating node invariants (additional info stored in nodes)

unordered_map<int, tuple<int,int,int>> keys;

tuple<int,int,int> key_of_team(int i) {
    return keys[i];
}
void update_key(int i, tuple<int,int,int> tup) {
    keys[i] = tup;
}

int main() {
    int n, m;
    cin >> n >> m;
    ost tree;

    // generate teams
    for (int i = 1; i <= n; i++) {
        auto tup = make_tuple(0,0,i);
        tree.insert(tup); // these two must be the same
        update_key(i, tup);
    }

    // calculate points
    for (int i = 0; i < m; i++) {
        int team, penalty;
        cin >> team >> penalty;
        auto old_key = key_of_team(team); // guaranteed unique
        auto [oldScore, oldPenalty, _] = old_key;
        tree.erase(old_key);

        auto new_key = make_tuple(oldScore-1,oldPenalty+penalty,_);
        update_key(team, new_key);
        tree.insert(new_key);

        cout << tree.order_of_key(key_of_team(1)) + 1 << endl;
    }
}