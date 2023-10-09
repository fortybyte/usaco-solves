// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<char> a,b;
	//input
	for (int i = 0; i < 9; i ++) {
		char cur;
		cin >> cur;
		a.push_back(cur);
	}
	for (int i = 0; i < 9; i ++) {
		char cur;
		cin >> cur;
		b.push_back(cur);
	}

	vector<bool> used(9);
	int green = 0; //calculate amt green
	for (int i = 0; i < 9; i ++) {
		if (a[i] == b[i]) {
			green ++;
			used[i] = true;
		}
	}

	unordered_map<char,int> mp1, mp2; //map for storing counts
	int yellow = 0;
	for (int i = 0 ; i < 9; i ++) {
		if (!used[i]) {
			mp1[a[i]] ++;
			mp2[b[i]] ++;
		}
	}

	for (auto [k,v] : mp1) {
		if (mp2.find(k) != mp2.end()) { //found
			yellow+= min(mp2[k],v);
		}
	}

	cout << green << endl << yellow;

}
