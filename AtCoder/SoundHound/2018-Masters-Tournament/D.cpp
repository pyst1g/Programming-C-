// finish date: 2018/07/07
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>>
        vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>>
        vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
const int bigmod = 1000000007;
const int INF = 1050000000;

vl dijkstra(int s, int V, vector<vector<pli>> edge) {
    vl dist(V, LONG_LONG_MAX / 4); //INFの値がこれでいいか確認するべき
    vb used(V, false);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(pli(0, s));
    while (!pq.empty()) {
        ll d;
        int t;
        tie(d, t) = pq.top();
        pq.pop();
        if (used[t]) continue;
        used[t] = true;
        dist[t] = d;
        for (pli e:edge[t]) {
            if (dist[e.second] < d + e.first) continue;
            pq.push(pli(d + e.first, e.second));
        }
    }
    return dist;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    vector<vector<pli>> yen(n);
    vector<vector<pli>> snuke(n);
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        yen[u].push_back(pli(a, v));
        yen[v].push_back(pli(a, u));
        snuke[u].push_back(pli(b, v));
        snuke[v].push_back(pli(b, u));
    }
    vl distY = dijkstra(s, n, yen);
    vl distS = dijkstra(t, n, snuke);
    vl ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = distY[i] + distS[i];
        if (i != n - 1) ans[i] = min(ans[i], ans[i + 1]);
    }
    rep(i, n) {
        cout << (ll) (round(pow(10, 15))) - ans[i] << endl;
    }
    return 0;
}

