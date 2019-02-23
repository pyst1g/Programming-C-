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


//足し算
int add(int a, int b) {
    return (int) (((ll) a + b + bigmod) % bigmod);
}

//引き算
int sub(int a, int b) {
    return (int) (((ll) a - b + bigmod) % bigmod);
}


int main() {
    int N, K;
    cin >> N >> K;
    vi a(N);
    rep(i, N) cin >> a[i];
    vvi dp(N, vi(K + 2, 0));
    rep(i, a[0] + 1) dp[0][i] = 1;

    rep(i, N - 1) {
        rep(j, K + 1) {
            dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
            dp[i + 1][min(K + 1, j + a[i + 1] + 1)] = sub(dp[i + 1][min(K + 1, j + a[i + 1]) + 1], dp[i][j]);
        }
        FOR(j, 1, K + 2) dp[i + 1][j] = add(dp[i + 1][j], dp[i + 1][j - 1]);
    }

    cout << dp[N - 1][K] << endl;

    return 0;
}