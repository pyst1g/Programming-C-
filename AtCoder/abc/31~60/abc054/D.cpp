// finish date: 2018/01/15
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

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    const int maxa = 401;
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<vector<vector<int>>> DP(N + 1, vector<vector<int>>(maxa + 1, vector<int>(maxa + 1, INF)));
    DP[0][0][0] = 0;
    int a, b, c;
    rep(k, N) {
        cin >> a >> b >> c;
        rep(i, k * 10 + 1) {
            rep(j, k * 10 + 1) {
                if (DP[k][i][j] != INF) {
                    DP[k + 1][i][j] = min(DP[k + 1][i][j], DP[k][i][j]);
                    DP[k + 1][i + a][j + b] = min(DP[k + 1][i + a][j + b], DP[k][i][j] + c);
                }
            }
        }
    }
    int mi = INF;
    rep(i, maxa) {
        rep(j, maxa) {
            if (i == 0 && j == 0) continue;
            if (i % Ma == 0 && j % Mb == 0 && i / Ma == j / Mb) {
                mi = min(mi, DP[N][i][j]);
            }
        }
    }
    if (mi == INF) cout << -1 << endl;
    else cout << mi << endl;

    return 0;
}
