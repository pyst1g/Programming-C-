// finish date: 2018/08/02
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
    int N, K;
    cin >> N >> K;
    vi b(N + 1, 0);
    vvl dp(N + 1, vl(2, LONG_LONG_MIN));
    dp[0][0] = dp[0][1] = 0;
    FOR(i, 1, N + 1) cin >> b[i];

    FOR(i, 1, N + 1) {
        if (i - K > 0) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + b[i]);
        }
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + b[i]);
        if (i - K >= 0) {
            dp[i][0] = max(dp[i][0], dp[i - K][1]);
        }
    }
    cout << max(dp[N][0], dp[N][1]) << endl;


    return 0;
}

