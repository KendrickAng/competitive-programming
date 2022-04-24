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
using ld = long double;
const ld  prec = .000001;

struct point {
    ld x, y;
    point(ld xloc, ld yloc) : x(xloc), y(yloc) {}
    point() {}
    point& operator= (const point& other) {
        x = other.x, y = other.y;
        return *this;
    }
    int operator== (const point& other) const {
        return abs(other.x - x) < prec && abs(other.y - y) < prec;
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (abs(other.x - x) < prec && y < other.y));
    }
};

struct vect {
    ld i, j;
};

ld crossproduct(point a, point b, point c) {
    vect ab, ac;
    ab.i = b.x - a.x;
    ab.j = b.y - a.y;
    ac.i = c.x - a.x;
    ac.j = c.y - a.y;
    return (ab.i * ac.j - ab.j * ac.i);
}

ld pointsquareddist(point a, point b) {
    return pow(a.x-b.x, 2) + pow(a.y-b.y,2);
}

ld area(vector<point> v) {
    ld total = 0;
    int n = v.size();
    for(int i=0, j=1; i < n; i++, j=(i+1)%n) {
        total += (v[i].x * v[j].y) - (v[i].y * v[j].x);
    }
    return abs(total) / 2;
}

vector<point> convex(vector<point> x) {
    vector<point> hull;
    ll size = x.size();
    vector<bool> used(size, false);

    int p = 0;
    for(int i = 1; i < size; i++) {
        if(x[i].x < x[p].x) {
            p = i;
        }
    }
    int start = p;

    do {
        int n = -1;
        ld dist = 0;

        for(int i = 0; i < size; i++) {
            if(i == p || used[i]) {
                continue;
            }
            if(n == -1) {
                n = i;
            }
            ld cross = crossproduct(x[p], x[i], x[n]);
            ld d = pointsquareddist(x[i], x[p]);

            if(cross < 0 || (abs(cross) < prec && d > dist)) {
                n = i;
                dist = d;
            }
        }

        p = n;
        used[p] = true;
        hull.push_back(x[p]);
    } while(start != p);

    return hull;
}

point rotate(point p, point c, ld angle) {
    ld x = p.x - c.x;
    ld y = p.y - c.y;
    ld hyp = sqrt(pow(x,2)+pow(y,2));

    ld oldangle = atan2(y,x);
    angle = -angle + oldangle;

    ld newx = hyp * cos(angle);
    ld newy = hyp * sin(angle);

    return {c.x+newx,c.y+newy};
}

void solve() {
    int N; cin >> N;
    vector<point> pts;
    ld usedArea = 0.0;
    while (N--) {
        ld x, y, w, h, v; cin >> x >> y >> w >> h >> v;
        v /= 180.0 / M_PI;
        usedArea += w*h;
        w /= 2; h /= 2;
        point c(x, y);
        point one = rotate({x+w, y+h}, c, v);
        point two = rotate({x+w, y-h}, c, v);
        point three = rotate({x-w, y-h}, c, v);
        point four = rotate({x-w, y+h}, c, v);
        pts.push_back(one);
        pts.push_back(two);
        pts.push_back(three);
        pts.push_back(four);
    }
    vector<point> hull = convex(pts);
    ld totalArea = area(hull);
    ld ans = (usedArea/totalArea) * 100.0;

    cout << fixed << setprecision(1) << ans << " %" << endl;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}