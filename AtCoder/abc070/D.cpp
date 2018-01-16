// finish date: 2018/01/16
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


using edge = struct {
    int to;
    ll cost;
};


vector<ll> d;
vector<vector<edge>> tree;

void dfs(int num, ll cost) {
    d[num] = cost;
    for (auto e:tree[num]) {
        if (d[e.to] != -1) continue;
        dfs(e.to, d[num] + e.cost);
    }
}


int main() {
    int N;
    cin >> N;
    d = vector<ll>(N, -1);
    tree = vector<vector<edge>>(N);

    int a, b, c;
    rep(i, N - 1) {
        cin >> a >> b >> c;
        a--;
        b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int Q, K;
    cin >> Q >> K;
    dfs(K - 1, 0);
    int x, y;
    rep(i, Q) {
        cin >> x >> y;
        cout << d[x - 1] + d[y - 1] << endl;
    }

    return 0;
}
