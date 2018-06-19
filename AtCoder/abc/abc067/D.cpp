// finish date: 2018/05/20

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

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
    int N;
    cin >> N;
    vector<vector<pii>> edge(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(make_pair(1, b));
        edge[b].push_back(make_pair(1, a));
    }
    vi dis1 = dijkstra(0, N, edge);
    vi dis2 = dijkstra(N - 1, N, edge);
    int point1 = 0, point2 = 0;
    FOR(i, 1, N - 1) {
        if (dis1[i] <= dis2[i]) point1++;
        else point2++;
    }
//    point1 += (N - (point1 + point2 + 2) + 1) / 2;
//    point2 += (N - (point1 + point2 + 2)) / 2;
    if (point1 > point2) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;

    return 0;
}


