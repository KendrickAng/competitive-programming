#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using ll = long long;
using ii = pair<int, int>;

class Coconut {
private:
    int player;
    int life;
public:
    Coconut(int player, int life=2) {
        this->player = player;
        this->life = life;
    }
    Coconut(const Coconut& other): Coconut(other.player, other.life) {
    }
    bool isFolded() {
        return life == 2;
    }
    bool isFist() {
        return life == 1;
    }
    void update() {
        life--;
    }
    int getPlayer() {
        return player+1;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int S, P; cin >> S >> P;
    S--;

    vector<Coconut> seats;
    for (int i = 0; i < P; i++) seats.push_back(Coconut(i));

    int next = 0;
    while (seats.size() > 1) {
        next = (next + S) % seats.size();
        if (seats[next].isFolded()) {
            seats[next].update();
            seats.insert(seats.begin()+next, Coconut(seats[next])); // copy constructor
        } else if (seats[next].isFist()) {
            seats[next].update();
            next++;
        } else {
            seats.erase(seats.begin() + next);
        }
    }
    cout << seats.front().getPlayer() << endl;
}