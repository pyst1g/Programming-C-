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
    vvi abc(N, vi(3)), dp(N, vi(3, 0));
    rep(i, N) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
    dp[0][0] = abc[0][0], dp[0][1] = abc[0][1], dp[0][2] = abc[0][2];
    FOR(i, 1, N) {
        dp[i][0] = max(dp[i][0], abc[i][0] + max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = max(dp[i][1], abc[i][1] + max(dp[i - 1][0], dp[i - 1][2]));
        dp[i][2] = max(dp[i][2], abc[i][2] + max(dp[i - 1][0], dp[i - 1][1]));
    }
    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << endl;

    return 0;
}