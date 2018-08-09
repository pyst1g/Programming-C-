// finish date: 2018/01/14
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 1000000000

vector<vector<int>> b, c, field;


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, INF));
    int u, v, l;
    vector<int> neighbor, distance;
    rep(i, M) {
        cin >> u >> v >> l;
        if (u == 1 || v == 1) {
            neighbor.emplace_back((u == 1) ? v - 1 : u - 1);
            distance.emplace_back(l);
        }else {
            graph[u - 1][v - 1] = l;
            graph[v - 1][u - 1] = l;
        }
    }
//    if (neighbor.size() <= 2) {
//        cout << -1 << endl;
//        return 0;
//    }
    rep(i, N) graph[i][i] = 0;
    //ワーシャルフロイド
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    int mi = INF;
    int ni, nj;
    rep(i, neighbor.size()) {
        FOR(j, i+1, neighbor.size()) {
            ni = neighbor[i];
            nj = neighbor[j];
            if (graph[ni][nj] == INF) continue;
            mi = min(mi, distance[i] + distance[j] + graph[ni][nj]);
        }
    }
    if (mi == INF) cout << -1 << endl;
    else cout << mi << endl;

    return 0;
}
