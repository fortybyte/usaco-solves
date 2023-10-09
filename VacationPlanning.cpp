#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 205;
const long long INF = 1e18;

long long dist[MAX_N][MAX_N];

int main() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        dist[u][v] = min(dist[u][v], (long long)d); // In case of multiple paths, take the shorter one.
    }

    // Floyd-Warshall
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int validTrips = 0;
    long long totalCost = 0;

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        long long minCost = INF;

        for(int h = 1; h <= K; h++) {
            if(dist[a][h] != INF && dist[h][b] != INF)
                minCost = min(minCost, dist[a][h] + dist[h][b]);
        }

        if(minCost != INF) {
            validTrips++;
            totalCost += minCost;
        }
    }

    cout << validTrips << "\n" << totalCost << "\n";
    return 0;
}
