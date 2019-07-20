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
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(make_pair(1, b));
        edge[b].push_back(make_pair(1, a));
    }
    vvi dis(N);
    rep(i, N) {
        dis[i] = dijkstra(i, N, edge);
    }
    int maxdis = 0;
    int node1, node2;
    rep(i, N) {
        rep(j, N) {
            if (maxdis < dis[i][j]) {
                maxdis = dis[i][j];
                node1 = i;
                node2 = j;
            }
        }
    }
    vi maxLeaf1(N, 0);
    vi maxLeaf2(N, 0);
    rep(i, N) {
        if (edge[i].size() == 1) {
            maxLeaf1[dis[i][node1]]++;
            maxLeaf2[dis[i][node2]]++;
        }
    }
    int ma = 0;
    rep(i, N) {
        ma += max(maxLeaf1[i], maxLeaf2[i]);
    }
    if (maxdis % 2 == 0) {
        cout << (maxdis+2) / 2 << " " << ma << endl;
    } else {
        cout << (maxdis + 2) / 2 << " " << ma  << endl;
    }


    return 0;
}


