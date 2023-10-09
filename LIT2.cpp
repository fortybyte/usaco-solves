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
// bool op(const pll& a, const pll& b) {
// 	return a.f < b.f || (a.f == b.f && a.s < b.s);
// }
struct e{
	vector<int> coins;
	e (vector<int>& a) {
		coins = a;
	}
};
int f1(const vi& cur) {
	int cnt = 0;
	for (auto i : cur) {
		cnt += i;
	}
	
	return cnt;
}
int sum(const vi& cur, const vi& nums) {
	int res = 0;
	for (int i = 0; i < 5; i ++) {
		res += cur[i] * nums[i];
	}
	return res;
}
void solve() {
	int n; cin >> n;
	vi nums(5);
	INV(nums,5)
	ll cnt = 0;
	queue<e> q;
	vi start = {0,0,0,0,0};
	q.push(e(start));
	while(!q.empty()) {
		vi cur = q.front().coins;
		q.pop();
		if (f1(cur)== 6) {
			if (sum(cur, nums) == n) cnt ++;
		} else if (f1(cur) < 6) {
			for (int i = 0; i < 5; i ++) {
				vi c = cur;
				c[i] ++;
				q.push(e(c));
			}
		}
	}
	OUT(cnt)
}
int main() {
	SETIO
	// int t;
	// loopT(t) {
	// 	solve();
	// }
	solve();
}
