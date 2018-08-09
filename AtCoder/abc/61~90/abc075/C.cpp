// finish date: 2018/01/24
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 500000000

int N, M;
vi a, b;
vvb graph;
vb visited;

void dfs(int v) {
    visited[v] = true;
    rep(i, N) {
        if (!graph[v][i]) continue;
        if (visited[i]) continue;
        dfs(i);
    }
}

int main() {
    cin >> N >> M;
    a = vi(M);
    b = vi(M);
    graph = vvb(N, vb(N, false));
    visited = vb(N);
    int ans = 0;

    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    rep(i, M) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
        rep(i, N) visited[i] = false;
        dfs(0);
        rep(i, N) {
            if (!visited[i]) {
                ans++;
                break;
            }
        }
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }
    cout << ans << endl;
    return 0;
}

