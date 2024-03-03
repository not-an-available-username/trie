#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using str = string;
 
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdb = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vdb = vector<db>;
using vs = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdb = vector<pdb>;
 
using mii = map<int, int>;
using mll = map<ll, ll>;
using si = set<int>;
using sc = set<char>;
 
#define fi first
#define se second
 
#define sz(x) int((x).size())
#define all(x) x.begin(), x.end()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define pf push_front
 
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
 
#define FOR(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define ROF(i,a,b) for (int (i) = (b)-1; (i) >= (a); --(i))
#define each(a,x) for (auto& a: x)
 
template<class T> bool minimize(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool maximize(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int MAXN = 1e5 + 5;
const ll MOD = 1e9+7;
const ll INF = 1e18;
const db PI = 3.1415926535897932384626433832795;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
const bool testcase = false;
const str file = "";
 
map<str, int> mp;
 
struct node {
	node *child[26];
	int exist, val;
	str save;
	node() {
		memset(child, NULL, sizeof(child));
		exist = 0;
		val = 0;
		save = "";
	}
};
 
node *root = new node();
 
void add (str s, int x) {
	node *u = root;
	FOR(i, 0, sz(s)) {
		int k = s[i] - 'a';
		if (u -> child[k] == NULL) u -> child[k] = new node();
		u = u -> child[k];
		if (u -> val < x) {
            u -> val = x;
            u -> save = s;
		} else if (u -> val == x) {
            if (u -> save > s) 
                u -> save = s;
		}
	}
	u -> exist++;
}
 
void query (str s) {
	node *u = root;
	FOR(i, 0, sz(s)) {
		int k = s[i] - 'a';
		if (u -> child[k] == NULL) {
            cout << "-1\n";
            return;
		}
		u = u -> child[k];
	}
	cout << u -> save  << " " << u -> val << "\n";
}
 
void solve() {
    int n, q;
    vector<str> v;
 
    cin >> n;
    FOR(i, 0, n) {
        str s;
        cin >> s;
        v.pb(s);
        mp[s]++;
    }
 
    FOR(i, 0, n) {
        add(v[i], mp[v[i]]);
    }
 
    cin >> q;
    while (q--) {
        str s;
        cin >> s;
        query(s);
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen((file+".INP").c_str(), "r", stdin);
//    freopen((file+".OUT").c_str(), "w", stdout);
 
    int tc; tc = 1;
    if (testcase) cin >> tc;
    FOR(t, 0, tc) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
