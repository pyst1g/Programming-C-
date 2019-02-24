// finish date: 2019/2/23

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

//足し算
int add(int a, int b) {
    return (int) (((ll) a + b + bigmod) % bigmod);
}

int main() {
    int N;
    cin >> N;
    vvi a(N, vi(N));
    rep(i, N) rep(j, N) cin >> a[i][j];
    vvi dp(N, vi(1 << N, 0));

    rep(i, N) dp[0][1 << i] = a[0][i];
    vvi focus(N+1);
    rep(i, 1 << N) focus[__builtin_popcount(i)].push_back(i);


    rep(i, N - 1) {
        for(int j:focus[i+1]) {
            rep(k, N) {
                if (a[i + 1][k] && !(j & (1 << k))) {
                    dp[i + 1][j | (1 << k)] = (int) (((ll) dp[i + 1][j | (1 << k)] + dp[i][j] + bigmod) %
                                                     bigmod);//add(dp[i + 1][j | (1 << k)], dp[i][j]);
                }
            }
        }
    }
    cout << dp[N - 1][(1 << N) - 1] << endl;

    return 0;
}