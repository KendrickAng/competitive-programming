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
using ull = unsigned long long;

const ull B = 27; // base
const ull MOD = 2147483659ULL; // prime modulus
vector<ull> prefix;
vector<ull> suffix;

ull powmod(ull B, int e) {
  if (e == 0) return 1;
  if (e % 2 == 1) {
    return (powmod(B, e-1) * B) % MOD;
  } else {
    ull t = powmod(B, e/2);
    return (t * t) % MOD;
  }
}

long long extEuclid(long long a, long long b, long long &x, long long &y) {    // pass x and y by ref
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {                                    // repeats until b == 0
    long long q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

long long modInverse(long long b, long long m) {                   // returns b^(-1) (mod m)
  long long x, y;
  long long d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return (x+m)%m;                                // this is the answer
}

ull hashdumb(const string &s) {
    ull ans = 0;
    for (char c: s) {
        ans = (ans * B) % MOD;
        ans = (ans + (c-'a'+1)) % MOD;
    }
    return ans;
}

ull hashf(const string &s) {
    prefix.clear();
    suffix.clear();
    ull sub = 0;
    for (char c: s) {
        sub = (sub * B) % MOD;
        sub = (sub + (c-'a'+1)) % MOD;
    }

    ull pre = 0;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        pre = (pre * B) % MOD;
        pre = (pre + (c-'a'+1)) % MOD;
        prefix.push_back((pre * powmod(B, n-i-1)) % MOD);
        suffix.push_back(sub);
        ull tmp = ((s[i]-'a'+1) * powmod(B, n-1-i)) % MOD;
        sub = ((sub + MOD) - tmp) % MOD;
    }

    return pre;
}

ull remove(const string &s, ull h, int i) {
    if (i == 0) return suffix[i+1] % MOD;
    if (i == s.size()-1) return (prefix[i-1] * modInverse(B, MOD)) % MOD;
    int n = (int) s.size();
    return ((prefix[i-1] * modInverse(B, MOD)) + suffix[i+1]) % MOD;
}

ull insert(const string &s, ull h, int i, char c) {
    int n = s.size();
    if (i == 0) {
        ull sub = ((c-'a'+1)%MOD) * (powmod(B, n)%MOD) % MOD;
        return (suffix[0] + sub) % MOD;
    }
    if (i == n) return (((suffix[0]* B%MOD) % MOD) + (c-'a'+1)%MOD) % MOD;
    ull sub = ((c-'a'+1) * powmod(B, n-i)) % MOD;
    return (((prefix[i-1]*B + sub) % MOD) + suffix[i]) % MOD;
}

ull replace(const string &s, ull h, int i, char c) {
    int n = s.size();
    ull sub1 = ((s[i]-'a'+1)%MOD *powmod(B, n-i-1)) % MOD;
    ull sub2 = ((c-'a'+1)%MOD *powmod(B, n-i-1)) % MOD;
    return ((suffix[0] - sub1) % MOD + sub2) % MOD;
}

ull exchange(const string &s, ull h, int i, int j) {
    assert(i < j and abs(i-j) == 1);
    int n = s.size();
    ull sub1 = ((s[i]-'a'+1)%MOD *powmod(B, n-i-1)) % MOD;
    ull sub2 = ((s[j]-'a'+1)%MOD *powmod(B, n-j-1)) % MOD;
    ull sub3 = ((s[i]-'a'+1)%MOD *powmod(B, n-j-1)) % MOD;
    ull sub4 = ((s[j]-'a'+1)%MOD *powmod(B, n-i-1)) % MOD;
    return ((suffix[0] - sub1 - sub2 + sub3 + sub4) + MOD) % MOD;
}

void solve() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string tmp;
    string input;
    while (getline(cin, tmp)) {
        if (tmp == "***") break;
        tmp += '\n';
        for (char c: tmp) {
            if (isalpha(c)) input.push_back(tolower(c));
            else if (isspace(c)) input.push_back(c);
        }
    }
    // debug(input);

    stringstream ss(input);
    vector<string> tokens;
    while (ss >> tmp) tokens.push_back(tmp);
    // debug(tokens);

    set<pair<int, ull>> hashes;
    map<string, set<string>> stuff;
    for (string &s: tokens) {
        ull h = hashdumb(s);
        // debug(s.size(), s, h);
        hashes.insert({s.size(), h});
    }

    for (string &word: tokens) {
        int n = word.size();
        ull h = hashf(word);
        for (int i = 0; i < n; i++) {
            ull removed = remove(word, h, i);
            if (hashes.find({n-1,removed}) != hashes.end()) {
                string removedS = word.substr(0,i) + word.substr(i+1);
                stuff[removedS].insert(word);
            }

            if (i != n-1 and (word[i] != word[i+1])) {
                // if (word[i] == word[i+1]) continue;
                ull exchanged = exchange(word, h, i, i+1);
                if (hashes.find({n,exchanged}) != hashes.end()) {
                    // debug(word, i, i+1);
                    string copied(word);
                    swap(copied[i], copied[i+1]);
                    stuff[copied].insert(word);
                }
            }
            for (char c = 'a'; c <= 'z'; c++) {
                if (word[i] == c) continue;
                ull replaced = replace(word, h, i, c);
                if (hashes.find({n,replaced}) != hashes.end()) {
                    string copied(word);
                    // debug(word, i, c, "replace");
                    copied[i] = c;
                    stuff[copied].insert(word);
                }
            }
        }

        // insert at front or back
        for (int i = 0; i <= n; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                ull inserted = insert(word, h, i, c);
                if (hashes.find({n+1,inserted}) != hashes.end()) {
                    // debug(word, i, c, "insert");
                    string insertedS = word.substr(0,i) + c + word.substr(i);
                    stuff[insertedS].insert(word);
                }
            }
        }
    }

    if (stuff.empty()) {
        cout << "***" << endl;
    } else {
        for (auto &[key, val]: stuff) {
            cout << key << ": "; 
            for (auto &s: val) {
                cout << s << " ";
            }
            cout << '\n';
        }
    }
}

void test() {
    // test deletion
    ull br = hashf("br");
    ull ar = hashf("ar");
    ull ab = hashf("ab");
    cout << "br " << br << endl;
    cout << "ar " << ar << endl;
    cout << "ab " << ab << endl;
    string s = "abr";
    ull abr = hashf(s);
    cout << s << " hash is " << abr << endl;
    cout << remove(s, abr, 0) << endl;
    cout << remove(s, abr, 1) << endl;
    cout << remove(s, abr, 2) << endl;
    // test insertion
    cout << "testing insertion" << endl;
    ar = hashf("ar");
    cout << "ar -> abr " << insert("ar", ar, 1, 'b') << endl;
    br = hashf("br");
    cout << "br -> abr " << insert("br", br, 0, 'a') << endl;
    ab = hashf("ab");
    cout << "ab -> abr " << insert("ab", ab, 2, 'r') << endl;
    ull lose = hashf("lose");
    cout << "close is " << hashdumb("close") << endl;
    cout << "lose -> close " << insert("lose", lose, 0, 'c') << endl;
    ull clos = hashf("clos");
    cout << "clos -> close " << insert("clos", clos, 4, 'e') << endl;
    // test replace
    cout << "testing replace" << endl;
    ull abb = hashf("abb");
    cout << "abb -> abr " << replace("abb", abb, 2, 'r') << endl;
    ull bbr = hashf("bbr");
    cout << "bbr -> abr " << replace("bbr", bbr, 0, 'a') << endl;
    ull azr = hashf("azr");
    cout << "azr -> abr " << replace("azr", azr, 1, 'b') << endl;
    // test exchange
    cout << "testing exchange " << endl;
    ull bar = hashf("bar");
    cout << "bar -> abr " << exchange("bar", bar, 0, 1) << endl;
    ull arb = hashf("arb");
    cout << "arb -> abr " << exchange("arb", arb, 1, 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // test();
    solve();
}