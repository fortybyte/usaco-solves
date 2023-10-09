#include <bits/stdc++.h>
using namespace std;
int nxtint() {
    int a;
    cin >> a;
    return a;
}
char nxtchar() {
    char c;
    cin >> c;
    return c;
}


int main() {
	int n = nxtint();
	vector<char> cows = vector<char>(n);
	for (int i = 0; i < n; i ++)  {
		cows[i] = nxtchar();
	}
	int count = 0;
	for (int i = n-1; i >= 1; i -= 2) {
		if (cows[i] == cows[i-1]) {
			continue;
		} 
		if (cows[i] == 'G' && count % 2 == 1) {
			count ++;
		}
        if (cows[i] == 'H' && count % 2 == 0){ // swap husternly to odd
            count ++;
		}
	}
	cout << count << endl;
	return 0;
}
