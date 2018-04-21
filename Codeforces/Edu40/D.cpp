// finish date: 2018/03/22

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>

//dijkstra(開始ノード、ノード数、edge[頂点名][距離、行先の頂点])
vi dijkstra(int s, int V, vector<vector<pii>> edge) {
    vi dist(V, INF); //INFの値がこれでいいか確認するべき
    vb used(V, false);
    priority_queue<pii, vector<pii >, greater<pii>> pq;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        int d, t;
        tie(d, t) = pq.top();
        pq.pop();
        if (used[t]) continue;
        used[t] = true;
        dist[t] = d;
        for (pii e:edge[t]) {
            if (dist[e.second] < d + e.first) continue;
            pq.push(pii(d + e.first, e.second));
        }
    }
    return dist;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    vector<vector<pii>> edge(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(pii(1, v));
        edge[v].push_back(pii(1, u));
    }
    vvi dist(n);
    rep(i, n) {
        dist[i] = dijkstra(i, n, edge);
    }
    int ans = 0;
    rep(i, n) {
        FOR(j, i + 1, n) {
//            if (i == s || i == t || j == s || j == t) continue;
            if (dist[s][i] + 1 + dist[j][t] >= dist[s][t] && dist[s][j] + 1 + dist[i][t] >= dist[s][t]) {
                if (dist[i][j] != 1) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}