#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");
    int n, cross=0;
    fin >> n;
    vector<bool> cow(10,0);
    vector<bool> valid(10,0);
    int id, side;
    for (int i=0;i<n;i++) {
        fin >> id >> side;
        id--;//zero index
        if (!valid[id]) {
            valid[id] = 1;
            cow[id] = side; 
        } else if (side != cow[id]) {
            cow[id] = side;
            cross ++;
        }
    }
    fout << cross;
}