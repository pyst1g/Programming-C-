// finish date: 2019/2/22

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

vi depth;
vb used;

int dfs(vector<set<int>> &path, int i) {
    if (used[i]) return depth[i] + 1;
    int ma = 0;
    for (int e: path[i]) {
        ma = max(ma, dfs(path, e));
    }
    used[i] = true;
    depth[i] = ma;
    return depth[i] + 1;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> path(N);
    depth = vi(N, 0);
    used = vb(N, false);
    int x, y;
    rep(i, M) {
        cin >> x >> y;
        x--, y--;
        path[x].insert(y);
    }
    int ma = 0;
    rep(i, N) {
        dfs(path, i);
        ma = max(ma, depth[i]);
    }

    cout << ma << endl;


    return 0;
}