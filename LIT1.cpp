// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
class def {

	//consts
	#define INTM (long long)0x3f3f3f3f3f
	#define INTN (int)1e5 + 10
	
	//breaks & continues
	#define break break;
	#define con continue;

	//misc
	#define all(x) x.begin(),x.end()
	#define ll long long
	#define lb long double
	#define sz(x) ((int)x.size())
	
	//1d vectors
	#define vll vector<ll>
	#define vi vector<int>
	#define vb vector<bool>
	#define v(x) vector<x>
	
	//2d vectors
	#define vvb vector<vector<bool>>
	#define vv(x) vector<vector<x>>
	#define vvi vector<vector<int>>
	#define vvll vector<vector<ll>>
	
	//pairs
	#define p(x) pair<x>
	#define pii pair<int,int>
	#define pll pair<ll,ll>
	#define f first
	#define s second

	//loops
	#define F0R(i, k) for (int i = 0; i <(k); i ++) 
	#define loopT(t) IN(t) while(t--)
	#define FOR(i, x, y) for (int i = x; i < y; i ++)

	//input
	#define IN(i) cin >> i;
	#define INV(i, n) for (int j = 0; j < n; j ++) {IN(i[j])} 
	#define INV2(v, n, m) for (int i = 0; i < n; i ++) {INV(v[i],m)}

	//output
	#define OUT(i) cout << i << "\n";
	#define out(i) cout << i << " ";
	#define OUTV(v) for(auto i : v) {cout << i << " ";}
	#define OUTV2(x) for (auto v : x) {OUTV(v) OUT("")}

	//configs
	#define SETIO ios::sync_with_stdio(false);cin.tie(0);
};
bool op(const pll& a, const pll& b) {
	return a.f < b.f || (a.f == b.f && a.s < b.s);
}
void solve() {
	int n; cin >> n;
	v(pll) nums(n); vvll dp(n+1,vll(2));
	//taken a two and not taken a two
	for (int i = 0; i < n; i ++) {
		IN(nums[i].f) IN(nums[i].s)
	}
	sort(all(nums),op);
	// for (auto p : nums) {
	// 	out(p.f) OUT(p.s)
	// }
	if (nums[0].s == 2) {
		dp[0][1] = 2;
	} else {
		dp[0][0] = dp[0][1] = 1;
	}
	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < 2; j ++) {
			int v = nums[i].s;
			if (v == 1 && j == 0) {
				dp[i][j] += dp[i-1][j] + v;
			} else if (v == 1 && j == 1) {
				dp[i][j] += dp[i-1][j];
			} else if (v == 2 && j == 0) {
				dp[i][j] += dp[i-1][j];
			} else if (v == 2 && j == 1) {
				dp[i][1] = max({dp[i-1][1], dp[i-1][0]}) + v;
			}
			//cout << i << ", " << j << " :  " << dp[i][0] << " // " << dp[i][1] << "\n";
		}
	}
	// OUT(dp[n-1][0])
	// OUT(dp[n-1][1])
	dp[n-1][1] = max(dp[n-1][0],dp[n-1][1]);
	OUT(dp[n-1][1] + (ll)1e9);
}
int main() {
	SETIO
	// int t;
	// loopT(t) {
	// 	solve();
	// }
	solve();
}
