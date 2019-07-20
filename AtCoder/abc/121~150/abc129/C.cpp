// finish date: 2019/06/09

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
    int N, M;
    cin >> N >> M;
    vi a(M);
    vb isbreak(N + 1, false);
    rep(i, M) {
        cin >> a[i];
        isbreak[a[i]] = true;
    }

    vi dp(N + 2, 0);
    dp[0] = 1;
    rep(i, N) {
        if (!isbreak[i + 1]) {
            dp[i + 1] = add(dp[i + 1], dp[i]);
        }
        if (!isbreak[i + 2]) {
            dp[i + 2] = add(dp[i + 2], dp[i]);
        }
    }

    cout << dp[N] << endl;
    return 0;
}


