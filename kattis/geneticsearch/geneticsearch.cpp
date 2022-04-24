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

const int MAX_N = 200010;

char T[MAX_N], P[MAX_N];                         // T = text, P = pattern
int n, m;                                        // n = |T|, m = |P|

// Knuth-Morris-Pratt's algorithm specific code
int b[MAX_N];                                    // b = back table

int naiveMatching() {
  int freq = 0;
  for (int i = 0; i < n; ++i) {                  // try all starting index
    bool found = true;
    for (int j = 0; (j < m) && found; ++j)
      if ((i+j >= n) || (P[j] != T[i+j]))        // if mismatch found
        found = false;                           // abort this, try i+1
    if (found) {                                 // T[i..i+m-1] = P[0..m-1]
      ++freq;
      // printf("P is found at index %d in T\n", i);
    }
  }
  return freq;
}

void kmpPreprocess() {                           // call this first
  int i = 0, j = -1; b[0] = -1;                  // starting values
  while (i < m) {                                // pre-process P
    while ((j >= 0) && (P[i] != P[j])) j = b[j]; // different, reset j
    ++i; ++j;                                    // same, advance both
    b[i] = j;
  }
}

int kmpSearch() {                               // similar as above
  int freq = 0;
  int i = 0, j = 0;                              // starting values
  while (i < n) {                                // search through T
    while ((j >= 0) && (T[i] != P[j])) j = b[j]; // if different, reset j
    ++i; ++j;                                    // if same, advance both
    if (j == m) {                                // a match is found
      ++freq;
      // printf("P is found at index %d in T\n", i-j);
      j = b[j];                                  // prepare j for the next
    }
  }
  return freq;
}

void loadPattern(const string &s) {
    m = s.size();
    strcpy(P, s.c_str());
    kmpPreprocess();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        // read input
        string text, pattern;
        cin >> pattern;
        if (pattern == "0") break;
        cin >> text;

        // init stuff
        int one = 0;
        int two = 0;
        int three = 0;
        n = text.size();
        m = pattern.size();
        strcpy(T, text.c_str());
        strcpy(P, pattern.c_str());
        kmpPreprocess();

        // case one
        one += kmpSearch();

        // case two
        set<string> twos;
        for (int i = 0; i < pattern.size(); i++) {
            twos.insert(pattern.substr(0, i) + pattern.substr(i+1));
        }
        for (const string &s: twos) {
            loadPattern(s);
            two += kmpSearch();
        }

        // case three
        set<string> threes;
        vector<char> stuff = {'A','T','G','C'};
        for (int i = 0; i <= pattern.size(); i++) {
            for (char c: stuff) {
                threes.insert(pattern.substr(0,i) + c + pattern.substr(i));
            }
        }
        for (const string &s: threes) {
            loadPattern(s);
            three += kmpSearch();
        }

        cout << one << " " << two << " " << three << endl;
    }
}