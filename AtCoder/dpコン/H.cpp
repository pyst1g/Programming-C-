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

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}


int main() {
    int H, W;
    cin >> H >> W;
    vvc a(H, vc(W));
    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }

    vvi dp(H, vi(W, 0));
    dp[0][0] = 1;
    FOR(i, 1, H) if (a[i][0] == '.') dp[i][0] = dp[i - 1][0];
    FOR(i, 1, W) if (a[0][i] == '.') dp[0][i] = dp[0][i - 1];
    FOR(i, 1, H) {
        FOR(j, 1, W) {
            if (a[i][j] == '.') dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[H - 1][W - 1] << endl;
    return 0;
}