// finish date: 2018/2/10

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
    int L;
    cin >> L;
    vl A(L);
    rep(i, L) cin >> A[i];

    vvl dp(5, vl(L, LONG_LONG_MAX));

    rep(i, 5) {
        rep(j, L) {
            switch (i) {
                case 0:
                    dp[i][j] = A[j];
                    if (j != 0) dp[i][j] += dp[i][j - 1];
                    break;

                case 1:
                    dp[i][j] = A[j] % 2;
                    if (A[j] == 0) dp[i][j] += 2;
                    if (j != 0) dp[i][j] += min(dp[i - 1][j - 1], dp[i][j - 1]);
                    break;

                case 2:
                    dp[i][j] = 1 - A[j] % 2;
                    if (j != 0) dp[i][j] += min({dp[0][j - 1], dp[1][j - 1], dp[2][j - 1]});
                    break;

                case 3:
                    dp[i][j] = A[j] % 2;
                    if (A[j] == 0) dp[i][j] += 2;
                    if (j != 0) dp[i][j] += min({dp[0][j - 1], dp[1][j - 1], dp[2][j - 1], dp[3][j - 1]});
                    break;

                case 4:
                    dp[i][j] = A[j];
                    if (j != 0) dp[i][j] += min({dp[0][j - 1], dp[1][j - 1], dp[2][j - 1], dp[3][j - 1], dp[4][j - 1]});

                default:
                    break;
            }
        }
    }

    ll mi = LONG_LONG_MAX;
    rep(i, 5)mi = min(mi, dp[i][L - 1]);

    cout << mi <<
         endl;
    return 0;
}