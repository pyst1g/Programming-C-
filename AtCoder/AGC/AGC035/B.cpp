// finish date: 2019/07/16

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

int N, M;
vvi allEdge;
vb passed;
vector<vector<pii>> treeEdge_down;
vi treeEdge_up;
vector<set<int>> treeSet;

void dfs(int v) {
    passed[v] = true;
    for (int to: allEdge[v]) {
        if (!passed[to]) {
            treeEdge_down[v].emplace_back(pii(1, to));
            treeEdge_up[to] = v;
            treeSet[v].insert(to);
            treeSet[to].insert(v);
            dfs(to);
        }
    }
}


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
    cin >> N >> M;
    if (M & 1) {
        cout << -1 << endl;
        return 0;
    }
    vi A(M), B(M);
    allEdge = vvi(N);
    treeEdge_down = vector<vector<pii>>(N);
    treeEdge_up = vi(N);
    treeSet = vector<set<int>>(N);
    passed = vb(N, false);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        allEdge[A[i]].emplace_back(B[i]);
        allEdge[B[i]].emplace_back(A[i]);
    }
    dfs(0);

    vi dim(N, 0);
    rep(i, M) {
        if (treeSet[A[i]].find(B[i]) == treeSet[A[i]].end()) {
            dim[A[i]]++;
            cout << A[i] + 1 << " " << B[i] + 1 << endl;
        }
    }

    vi dist = dijkstra(0, N, treeEdge_down);

    vvi priori(N, vi(3));
    rep(i, N) {
        priori[i] = {dist[i], i, treeEdge_up[i]};
    }
    sort(priori.begin(), priori.end());
    reverse(priori.begin(), priori.end());
    rep(i, N) {
        if (priori[i][1] == 0) continue;
        if (dim[priori[i][1]] & 1) {
            dim[priori[i][1]]++;
            cout << priori[i][1] + 1 << " " << priori[i][2] + 1 << endl;
        } else {
            dim[priori[i][2]]++;
            cout << priori[i][2] + 1 << " " << priori[i][1] + 1 << endl;
        }
    }

    return 0;
}
