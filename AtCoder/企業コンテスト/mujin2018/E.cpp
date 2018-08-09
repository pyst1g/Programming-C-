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

vi distU, distD, distL, distR;
int N, M, K;
vs s;

//dijkstra(開始ノード、ノード数、edge[頂点名][距離、行先の頂点])
vl dijkstra(int st, int V) {
    vl dist(V, INFll); //INFの値がこれでいいか確認するべき
    vb used(V, false);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(pli(0, st));
    while (!pq.empty()) {
        ll d;
        int t;
        tie(d, t) = pq.top();
        pq.pop();
        if (s[t / M][t % M] == '#') continue;
        if (used[t]) continue;
        used[t] = true;
        dist[t] = d;
        if (t - M >= 0 && distU[d%K] != INF) pq.push(pli(d + distU[d%K], t - M));
        if (t + M < V && distD[d%K] != INF) pq.push(pli(d + distD[d%K], t + M));
        if (t % M - 1 >= 0 && distL[d%K] != INF) pq.push(pli(d + distL[d%K], t - 1));
        if (t % M + 1 < M && distR[d%K] != INF) pq.push(pli(d + distR[d%K], t + 1));

//        for (pii e:edge[t]) {
//            if (dist[e.second] < d + e.first) continue;
//            pq.push(pii(d + e.first, e.second));
//        }
    }
    return dist;
}

int main() {
    cin >> N >> M >> K;
    distU = vi(K);
    distD = vi(K);
    distL = vi(K);
    distR = vi(K);
    string d;
    cin >> d;

    s = vs(N);
    rep(i, N) cin >> s[i];
    string str = d + d;
    int dU, dD, dL, dR;
    dU = dD = dL = dR = INF;
    for (int i = str.length() - 1; i >= 0; i--) {
        switch (str[i]) {
            case 'U':
                dU = 0;
                break;
            case 'D':
                dD = 0;
                break;
            case 'L':
                dL = 0;
                break;
            case 'R':
                dR = 0;
                break;
            default:
                cout << "ばかたれ" << endl;
        }
        dU = min(dU + 1, INF);
        dD = min(dD + 1, INF);
        dL = min(dL + 1, INF);
        dR = min(dR + 1, INF);
        if (i < K) {
            distU[i] = dU;
            distD[i] = dD;
            distL[i] = dL;
            distR[i] = dR;
        }
    }

    int S = 0, G = 0;
    rep(i, N) {
        rep(j, M) {
            if (s[i][j] == 'S') S = M * i + j;
            if (s[i][j] == 'G') G = M * i + j;
        }
    }

    vl dist = dijkstra(S, N * M);
    if(dist[G]==INFll) cout<<-1<<endl;
    else cout << dist[G] << endl;

    return 0;
}

