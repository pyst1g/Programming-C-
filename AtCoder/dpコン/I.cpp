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


int main() {
    int N;
    cin >> N;
    vd p(N);
    rep(i, N) cin >> p[i];
    vvd dp(N, vd(N + 1, 0));
    dp[0][0] = 1 - p[0];
    dp[0][1] = p[0];
    FOR(i, 1, N) {
        rep(j, N) {
            dp[i][j] += dp[i - 1][j] * (1 - p[i]);
            dp[i][j + 1] += dp[i - 1][j] * p[i];
        }
    }
    double ans = 0;
    FOR(i, N / 2 + 1, N + 1) {
        ans += dp[N - 1][i];
    }
    printf("%.10lf", ans);

    return 0;
}