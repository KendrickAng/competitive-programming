#include <bits/stdc++.h>

using namespace std;

/********************************* LIBRARY #1 **********************************/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
// Random n numbers between l and r
void num(int l, int r, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) << " ";
    }
}
 
//Random n real numbers between l and r with dig decimal places
void real(int l, int r, int dig, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << rand(l,r) <<"."<<rand(0,pow(10,dig)-1)<< " ";
    }
}
// Random n strings of length l
void str(int l, int n) {
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(v%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
}
// Random n strings of max length l
void strmx(int mxlen, int n) {
    for (int i = 0; i < n; ++i)
    {
        int l = rand(1,mxlen);
        for(int j = 0; j < l; ++j) {
            int v = rand(1,150);
            if(3%3==0) cout<<(char)rand('a','z');
            else if(v%3==1) cout<<(char)rand('A','Z');
            else cout<<rand(0,9);
        }
        cout<<" ";
    }
} 
// Random tree of n nodes
void tree(int n) {
    int prufer[n-2];
    for ( int i = 0; i < n; i++ ){
        prufer[i] = rand(1,n);
    }
    int m = n-2;
    int vertices = m + 2; 
    int vertex_set[vertices]; 
    for (int i = 0; i < vertices; i++) 
        vertex_set[i] = 0; 
    for (int i = 0; i < vertices - 2; i++) 
        vertex_set[prufer[i] - 1] += 1; 
    int j = 0; 
    for (int i = 0; i < vertices - 2; i++) { 
        for (j = 0; j < vertices; j++) { 
            if (vertex_set[j] == 0) { 
                vertex_set[j] = -1; 
                cout << (j + 1) << " "
                     << prufer[i] << '\n'; 
                vertex_set[prufer[i] - 1]--; 
                break; 
            } 
        } 
    } 
    j = 0; 
    for (int i = 0; i < vertices; i++) { 
        if (vertex_set[i] == 0 && j == 0) { 
            cout << (i + 1) << " "; 
            j++; 
        } 
        else if (vertex_set[i] == 0 && j == 1) 
            cout << (i + 1) << "\n"; 
    }
}

/********************************* END LIBRARY #1 **********************************/

/********************************* LIBRARY #2 **********************************/

using ll = long long;
const ll inf = 1e18;
const int mx = 1e5;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x=0, ll y=inf) {return (rng() % (y-x +1)) + x;};

namespace generator{
	ll get_num(ll a = 0 , ll b = inf){
		return rnd(a,b);
	}
	string get_string(int len = -1,bool lowercase_only = true){
		if(len==-1){
			len = rnd(1,mx);
		}
		string s(len,'0');
		for(int i = 0; i < len; i++)
			s[i] = (rnd(0,25) + 'a');
		if(lowercase_only) return s;
		for(auto&i:s){
			if(rng()&1) i^=32; // swap case (make c to C)
		}
		return s;
	}
	template<typename T>
	vector<T> get_array(int len = -1 , T a = 0,T b = inf){
		if(len==-1){
			len = rnd(1,mx);
		}
		vector<T> s(len);
		for(int i = 0; i < len; i++)
			s[i] = (rnd(a,b));
		return s;
	}
	vector<pair<int, int>> get_tree(int n = -1){
		if(n==-1) n = rnd(1,mx);
		vector<pair<int, int>> res(n-1);
		for(int i = 2; i <= n; i++){
			int u = i , v = rnd(1 , i-1);
			if(rng()&1) swap(u,v);
			res[i-2] = {u,v};
		}
		shuffle(res.begin() , res.end() , rng);
		return res;
	}
	vector<pair<int, int>> get_simple_graph(int n , int m , bool connected = true){
		vector<pair<int, int>> res;
		set<pair<int , int>> edge_set;
		assert(2*m <= 1ll*n*(n-1)); // maximum condition for edge
		if(connected){
			assert(m >= n-1); // minimum edges of connected graph
			res = get_tree(n);
			for(auto i:res) edge_set.insert(i);
			res.clear();
			for(int i = n; i <= m; i++){
				label:
				int u = rnd(1,n);
				int v = rnd(1,n);
				if(u==v or edge_set.count({u,v}) or edge_set.count({v,u})) goto label;
				else{
					edge_set.insert({u,v});
				}
			}

		}
		else{
			for (int i = 1; i <= m; ++i)
			{
				label2:
				int u = rnd(1,n);
				int v = rnd(1,n);
				if(u==v or edge_set.count({u,v}) or edge_set.count({v,u})) goto label2;
				else{
					edge_set.insert({u,v});
				}
			}
		}
		for(auto i:edge_set){
			res.push_back(i);
		}
		shuffle(res.begin() , res.end() , rng);
		return res;
	}
};

int main() {
	for (int i = 0; i < 9; i++) {
		int n = rand(1, 22);
		int t = rand(3, 90);
		cout << n << " " << t << endl;
		for (int i = 0; i < n; i++) {
			cout << rand(1, 30) << " ";
		}
		cout << endl;
	}
	cout << "0 0" << endl;
}