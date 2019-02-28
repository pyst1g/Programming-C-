// finish date: 2019/2/28

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

//引き算
int sub(int a, int b) {
    return (int) (((ll) a - b + bigmod) % bigmod);
}

int main() {
    string K;
    int D;
    cin >> K >> D;
    vvvi dp(K.length(), vvi(2, vi(D, 0)));
    rep(i, K[0] - '0') dp[0][0][i % D] += 1;
    dp[0][1][(K[0] - '0') % D] += 1;

    rep(i, K.length() - 1) {
        //dp[][0][]の場合
        rep(k, D) {
            rep(j, 10) {
                dp[i + 1][0][(k + j) % D] = add(dp[i + 1][0][(k + j) % D], dp[i][0][k]);
            }
        }

        //dp[][1][]の場合
        rep(k, D) {
            rep(j, K[i + 1] - '0') {
                dp[i + 1][0][(k + j) % D] = add(dp[i + 1][0][(k + j) % D], dp[i][1][k]);
            }
            dp[i + 1][1][(k + (K[i + 1] - '0')) % D] = add(dp[i + 1][1][(k + (K[i + 1] - '0')) % D], dp[i][1][k]);
        }
    }

    cout << sub(add(dp[K.length()-1][0][0], dp[K.length()-1][1][0]), 1) << endl;

    return 0;
}