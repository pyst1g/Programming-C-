// finish date: 2019/1/26

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
const int INF = 1000000007;
const long long INFll = 100000000000000000;


vvi warshall_floyd(vvi dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main() {
    int H, W;
    cin >> H >> W;
    vs S(H);
    rep(i, H) cin >> S[i];
    int N = H * W;
    vvi dist(N, vi(N, INF));
    rep(i, N) dist[i][i] = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            int x[] = {-1, 0, 1, 0};
            int y[] = {0, -1, 0, 1};
            rep(k, 4) {
                if ((0 <= i + y[k] and i + y[k] < H) and
                    (0 <= j + x[k] and j + x[k] < W) and
                    (S[i + y[k]][j + x[k]] == '.')) {
                    dist[i * W + j % W][(i + y[k]) * W + (j + x[k]) % W] = 1;
                }
            }
        }
    }


    dist = warshall_floyd(dist);
    int ma = 0;
    rep(i, N) {
        rep(j, N) {
            if (dist[i][j] != INF)
                ma = max(ma, dist[i][j]);
        }
    }
    cout << ma <<endl;

    return 0;
}
