// finish date: 2018/08/06
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
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    int N, M;
    cin >> N >> M;
    vs S(N);
    rep(i, N) cin >> S[i];
    vvi ri(N, vi(M, 0)), le(N, vi(M, 0)), up(N, vi(M, 0)), lo(N, vi(M, 0));

    rep(i, N) {
        rep(j, M) {
            if (S[i][j] == '#') {
                ri[i][j] = 0, lo[i][j] = 0;
                continue;
            }
            ri[i][j] = (j > 0) ? ri[i][j - 1] + 1 : 1;
            lo[i][j] = (i > 0) ? lo[i - 1][j] + 1 : 1;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (S[i][j] == '#') {
                le[i][j] = 0, up[i][j] = 0;
                continue;
            }
            le[i][j] = (j < M - 1) ? le[i][j + 1] + 1 : 1;
            up[i][j] = (i < N - 1) ? up[i + 1][j] + 1 : 1;
        }
    }
    ll ans = 0;
    rep(i, N) {
        rep(j, M) {
            if (S[i][j] == '#') continue;
            if (i > 0 && j > 0) ans += lo[i - 1][j] * ri[i][j - 1];
            if (j > 0 && i < N - 1) ans += ri[i][j - 1] * up[i + 1][j];
            if (i < N - 1 && j < M - 1) ans += up[i + 1][j] * le[i][j + 1];
            if (j < M - 1 && i > 0) ans += le[i][j + 1] * lo[i - 1][j];
        }
    }

    cout << ans << endl;

    return 0;
}

