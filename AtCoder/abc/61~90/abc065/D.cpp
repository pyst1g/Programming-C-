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

//prim(ノード数、edge[頂点名][距離、行先の頂点])
ll prim(int N, vector<vector<pii >> edge) {
    priority_queue<pii, vector<pii >, greater<pii>> pq;
    vb used(N, false);
    pq.push(pii(0, 0));
    ll total = 0;
    while (!pq.empty()) {
        int dis, t;
        tie(dis, t) = pq.top();
        pq.pop();
        if (used[t]) continue;
        used[t] = true;
        total += dis;
        for (auto e: edge[t]) {
            if (!used[e.second]) pq.push(e);
        }
    }
    return total;
}


int main() {
    int N;
    cin >> N;
    vector<pii > x(N), y(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        x[i] = make_pair(a, i);
        y[i] = make_pair(b, i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<vector<pii >> edge(N);
    FOR(i, 1, N) {
        edge[x[i - 1].second].push_back(make_pair(abs(x[i].first - x[i - 1].first), x[i].second));
        edge[x[i].second].push_back(make_pair(abs(x[i].first - x[i - 1].first), x[i - 1].second));
        edge[y[i - 1].second].push_back(make_pair(abs(y[i].first - y[i - 1].first), y[i].second));
        edge[y[i].second].push_back(make_pair(abs(y[i].first - y[i - 1].first), y[i - 1].second));

    }
    cout << prim(N, edge) << endl;

    return 0;
}


