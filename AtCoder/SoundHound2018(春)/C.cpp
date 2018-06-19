// finish date: 2018/06/06
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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000

struct graph {
    int L, R;
    vector <vector<int>> adj;

    graph(int L, int R) : L(L), R(R), adj(L + R) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v + L);
        adj[v + L].push_back(u);
    }

    int maximum_matching() {
        vector<int> visited(L), mate(L + R, -1);
        function<bool(int)> augment = [&](int u) { // DFS
            if (visited[u]) return false;
            visited[u] = true;
            for (int w: adj[u]) {
                int v = mate[w];
                if (v < 0 || augment(v)) {
                    mate[u] = w;
                    mate[w] = u;
                    return true;
                }
            }
            return false;
        };
        int match = 0;
        for (int u = 0; u < L; ++u) {
            fill(visited.begin(), visited.end(), 0);
            if (augment(u)) ++match;
        }
        return match;
    }
};

int main() {
    int r, c;
    cin >> r >> c;
    vs C(r);
    rep(i, r) cin >> C[i];
    graph g((r * c + 1) / 2, r * c / 2);
    int minus = 0;
    rep(i, r) {
        rep(j, c) {
            if (C[i][j] == '*') minus++;
            if ((i + j) % 2 || C[i][j] == '*') continue;
            int a[] = {-1, 0, 1, 0};
            int b[] = {0, 1, 0, -1};
            rep(k, 4) {
                if ((0 <= j + a[k] && j + a[k] < c) && (0 <= i + b[k] && i + b[k] < r) &&
                    C[i + b[k]][j + a[k]] == '.') {
                    g.add_edge((j + c * i) / 2, ((j + a[k]) + c * (i + b[k])) / 2);
                }
            }
        }
    }
    cout << r * c - minus - g.maximum_matching() << endl;
    return 0;
}




