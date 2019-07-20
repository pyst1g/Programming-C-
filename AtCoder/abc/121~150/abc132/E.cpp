// finish date: 2019/06/30

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;

////dijkstra(開始ノード、ノード数、edge[頂点名][距離、行先の頂点])
//dijkstra(開始ノード、ノード数、edge[頂点名][距離、行先の頂点])
vi dijkstra(int s, int V, vector<vector<pii>> edge) {
    vi dist(V, INF); //INFの値がこれでいいか確認するべき
    vb used(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
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
    int N, M;
    cin >> N >> M;
    vi u(M), v(M);
    vector<vector<pii>> edge(N * 3);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        edge[u[i]].emplace_back(pii(1,v[i] + N));
        edge[u[i] + N].emplace_back(pii(1,v[i] + N * 2));
        edge[u[i] + N * 2].emplace_back(pii(1,v[i]));
    }
    int S, T;
    cin >> S >> T;
    S--;
    T--;
    vi dist = dijkstra(S, N * 3, edge);
    if (dist[T] == INF) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << dist[T]/3 << endl;
    }


    return 0;
}
