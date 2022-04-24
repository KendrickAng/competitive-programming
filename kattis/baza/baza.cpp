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

struct vertex {
  char alphabet;
  bool isEnd;
  vector<int> ind;
  vector<vertex*> child;
  vertex(char a): alphabet(a), isEnd(false) { child.assign(26, NULL); }
};

class Trie {                                     // this is TRIE
private:                                         // NOT Suffix Trie
  vertex* root;
public:
  Trie() { root = new vertex('!'); }

  void insert(string word, int id) {                     // insert a word into trie
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) { // O(n)
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == NULL) cur->child[alphaNum] = new vertex(word[i]);
      cur = cur->child[alphaNum];
      cur->ind.push_back(id); // update indices
    }
    cur->isEnd = true;
  }

  bool search(string word) {                     // true if word in trie
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) { // O(m)
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == NULL)          // not found
        return false;
      cur = cur->child[alphaNum];
    }
    return cur->isEnd;                           // check exist flag
  }

  bool startsWith(string prefix) {               // true if match prefix
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
      int alphaNum = prefix[i]-'a';
      if (cur->child[alphaNum] == NULL)          // not found
        return false;
      cur = cur->child[alphaNum];
    }
    return true;                                 // reach here, return true
  }

  ll cost(string &word, int id) {
      ll cost = 0;
      vertex *cur = root;
      for (int i = 0; i < (int)word.size(); i++) {
          int alphaNum = word[i] - 'a';
          if (cur->child[alphaNum] == NULL) {
              break;
          }
          cur = cur->child[alphaNum];
          ll offset = upper_bound(cur->ind.begin(), cur->ind.end(), id) - cur->ind.begin();
          cost += offset;
      }
      return cost;
  }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Trie trie;
    unordered_map<string, int> originalIdx;

    // read input
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        trie.insert(s, i);
        originalIdx[s] = i;
    }

    // read and answer queries
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        string p; cin >> p;
        if (trie.search(p)) {
            // cout << p << " in trie " << to_string(originalIdx[p]) << endl;
            cout << trie.cost(p, originalIdx[p]) + originalIdx[p] + 1 << endl;
        } else {
            // cout << p << " not in trie" << endl;
            cout << trie.cost(p, N+2) + N << endl;
        }
    }
}