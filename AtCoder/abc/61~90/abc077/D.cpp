// finish date: 2018/08/07
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
    int K;
    cin >> K;

    vector<vector<pii>> edge(K);
    rep(i, K) {
        edge[i].push_back(pii(1, (i + 1) % K));
        edge[i].push_back(pii(0, (i * 10) % K));
    }

    cout << dijkstra(1, K, edge)[0] + 1 << endl;

    return 0;
}

