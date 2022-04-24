#define _USE_MATH_DEFINES
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

#define EARTH_RAD (6371009) // in meters

double gcDist(double pLa, double pLo, double qLa, double qLo, double r) {
  pLa *= M_PI/180; pLo *= M_PI/180;           // degree to radian
  qLa *= M_PI/180; qLo *= M_PI/180;
  return r * acos(cos(pLa)*cos(pLo)*cos(qLa)*cos(qLo) +
         cos(pLa)*sin(pLo)*cos(qLa)*sin(qLo) + sin(pLa)*sin(qLa));
}

double EuclideanDistance(double pLa, double pLo, // 3D version
                         double qLa, double qLo, double radius) {
  double phi1 = (90 - pLa) * M_PI/180;
  double theta1 = (360 - pLo) * M_PI/180;
  double x1 = radius * sin(phi1) * cos(theta1);
  double y1 = radius * sin(phi1) * sin(theta1);
  double z1 = radius * cos(phi1);

  double phi2 = (90 - qLa) * M_PI/180;
  double theta2 = (360 - qLo) * M_PI/180;
  double x2 = radius * sin(phi2) * cos(theta2);
  double y2 = radius * sin(phi2) * sin(theta2);
  double z2 = radius * cos(phi2);

  double dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
  return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int t; cin >> t;
    while (t--) {
        double pLa, pLo, qLa, qLo; cin >> pLa >> pLo >> qLa >> qLo;
        double ans = gcDist(pLa, pLo, qLa, qLo, EARTH_RAD) - EuclideanDistance(pLa, pLo, qLa, qLo, EARTH_RAD);
        cout << ans << endl;
    }
}