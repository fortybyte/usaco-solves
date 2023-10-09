// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
class def {

	//consts
	#define MAXINT (long long)INT64_MAX
	#define INTM (long long)1e9
	#define INTN 1e5 + 10
	
	//breaks & continues
	#define break break;
	#define con continue;

	//misc
	#define all(x) x.begin(),x.end()
	#define ll long long
	#define sz(x) ((int)x.size())
	
	//1d vectors
	#define vll vector<ll>
	#define vi vector<int>
	#define vb vector<bool>
	#define v(x) vector<x>
	#define pb(x) push_back(x)
	
	//2d vectors
	#define vvb vector<vector<bool>>
	#define vv(x) vector<vector<x>>
	#define vvi vector<vector<int>>
	#define vvll vector<vector<ll>>
	
	//pairs
	#define p(x,y) pair<x,y>
	#define pii pair<int,int>
	#define pll pair<ll,ll>
	#define f first
	#define s second
	#define makep(x,y) make_pair(x,y)

	//loops
	#define F0R(i, k) for (int i = 0; i <(k); i ++) 
	#define loopT(t) IN(t) while(t--)
	#define FOR(i, x, y) for (int i = x; i < y; i ++)

	//input
	#define IN(i) cin >> i;
	#define INV(i, n) for (int j = 0; j < n; j ++) {IN(i[j])} 
	#define INV2(v, n, m) for (int i = 0; i < n; i ++) {INV(v[i],m)}

	//output
	#define OUT(i) cout << i << endl;
	#define out(i) cout << i << " ";
	#define OUTV(v) for(auto i : v) {cout << i << " ";}
	#define OUTV2(x) for (auto v : x) {OUTV(v) OUT("")}

	//configs
	#define SETIO ios::sync_with_stdio(false);cin.tie(0);
};
struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
const int MAXN = 1e6;

struct z{
	int s,e;
	ll v;
	bool operator < (const z& b) const {
		return v < b.v;
	}
};
vector<int> tree[MAXN];  
int depth[MAXN];          
vector<vector<int>> parent(MAXN, vector<int>(20,-1));     


void binaryLifting(int node, int par, int dep) {
    depth[node] = dep;
    parent[node][0] = par;
    for (int i = 1; i < 20; i++) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        } else {
            parent[node][i] = -1;
        }
    }
    for (int child : tree[node]) {
        if (child != par) {
            binaryLifting(child, node, dep + 1);
        }
    }
}
int findLCA(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int lift(int u, int v) {
	for (int i = 0; i < 20; i ++) {
		//OUT(u<< " " << v<< " " << i)
		if ((v >>i ) & 1) {
			u = parent[u][i];
			if (u == -1) break;
		}
	}
	//OUT(' ')
	return u;
}
struct node{
	int pos;
	int use;
	ll w;
	bool operator < (const node& b) const {
		return w > b.w;
	}
};
//void post(int idx , )
void solve() {
	ll n;
	cin >> n;
	while(n!=1) {
		out(n)
		if (n%2) {
			n *= 3;
			n +=1;
		} else {
			n/=2;
		}
	}
	OUT(1)

}
int main() {
	SETIO
	// int t;
	// loopT(t) {
	// 	solve();
	// }
	solve();
}