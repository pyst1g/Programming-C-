// finish date: 2018/06/07
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


int main() {
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vs A(N);
    rep(i, N) cin >> A[i];
    int R = min(H, 2 * N + 1);
    int C = min(W, 2 * M + 1);
    vvi X(R + 1, vi(C + 1, 0));
    rep(i, N) {
        rep(j, M) {
            if (A[i][j] == '#') {
                X[i][j] += 1;
                X[i][C - M + j + 1] += -1;
                X[R - N + i + 1][j] += -1;
                X[R - N + i + 1][C - M + j + 1] += 1;
            }
        }
    }

    rep(i, R) {
        FOR(j, 1, C) {
            X[i][j] += X[i][j - 1];
        }
    }
    FOR(i, 1, R) {
        rep(j, C) {
            X[i][j] += X[i - 1][j];
        }
    }
    ll ans = 0;
    rep(i, min(H, R)) {
        rep(j, min(W, C)) {
            if (X[i][j] > 0) {
                if (i == N && j == M) {
                    ans += max((ll) 1, (ll) (max(0, H - 2 * N)) * (max(0, W - 2 * M)));
                } else if (i == N) {
                    ans += max(1, H - 2 * N);
                } else if (j == M) {
                    ans += max(1, W - 2 * M);
                } else {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}




