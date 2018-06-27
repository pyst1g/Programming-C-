// finish date: 2018/06/26
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

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
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;

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


class TeleportationMaze {
public:
    int pathLength(vector<string> a, int r1, int c1, int r2, int c2) {
        int R = a.size();
        int C = a[0].length();
        vi y = {0, 1};
        vi x = {1, 0};
        vector<vector<pii>> edge(R * C);
        rep(i, R) {
            rep(j, C) {
                if (a[i][j] == '#') continue;
                rep(k, 4) {
                    if (!((0 <= i + y[k] && i + y[k] < R) && (0 <= j + x[k] && j + x[k] < C))) continue;
                    if (a[i + y[k]][j + x[k]] == '#') continue;
                    edge[C * i + j].emplace_back(make_pair(1, C * (i + y[k]) + (j + x[k])));
                    edge[C * (i + y[k]) + (j + x[k])].emplace_back(make_pair(1, C * i + j));
                }
            }
        }
        rep(i, R) {
            int st = -1;
            int cnt = 0;
            rep(j, C) {
                if (a[i][j] == '#') {
                    cnt++;
                    continue;
                } else {
                    if (st != -1 && cnt != 0) {
                        edge[C * i + st].emplace_back(make_pair(2, C * i + j));
                        edge[C * i + j].emplace_back(make_pair(2, C * i + st));
                    }
                    cnt = 0;
                    st = j;
                }
            }
        }
        rep(j, C) {
            int st = -1;
            int cnt = 0;
            rep(i, R) {
                if (a[i][j] == '#') {
                    cnt++;
                    continue;
                } else {
                    if (st != -1 && cnt != 0) {
                        edge[C * st + j].emplace_back(make_pair(2, C * i + j));
                        edge[C * i + j].emplace_back(make_pair(2, C * st + j));
                    }
                    cnt = 0;
                    st = i;
                }
            }
        }
        vi dist = dijkstra(C * r1 + c1, R * C, edge);
        if(dist[C * r2 + c2] == INF) return -1;
        return dist[C * r2 + c2];
    }

};




