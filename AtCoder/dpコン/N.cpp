// finish date: 2019/2/23

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


int main() {
    int N;
    cin >> N;
    vl a(N);
    rep(i, N) cin >> a[i];
    vl acc(N + 1, 0);
    FOR(i, 1, N + 1) acc[i] = a[i - 1] + acc[i - 1];
    vvl dp(N, vl(N, INFll));
    rep(i, N) dp[i][i] = 0;

    int st, en;
    ll left, right;
    FOR(len, 2, N + 1) {
        rep(i, N) {
            st = i;
            en = i + len - 1;
            if (en >= N) break;
            FOR(j, st, en) {
                left = dp[st][j];
                right = dp[j + 1][en];
                dp[st][en] = min(dp[st][en], left + right + (acc[en+1] - acc[st]));
            }
        }
    }

    cout << dp[0][N - 1] << endl;

    return 0;
}