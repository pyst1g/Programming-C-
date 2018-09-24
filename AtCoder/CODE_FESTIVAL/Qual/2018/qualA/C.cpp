// finish date: 2018/09/23
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
typedef vector<vector<vector<double>>>
        vvvd;
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
    int N, K;
    cin >> N >> K;
    vi A(N);
    int sum = 0;
    rep(i, N) {
        ll a;
        cin >> a;
        int cnt = 0;
        while (a != 0) {
            a /= 2;
            cnt++;
        }
        sum += cnt;
        A[i] = cnt;
        //cout << A[i] << endl;
    }
    sum += 1;
    int mi = min(K+1, sum + 1);
    vvvi DP(N + 1, vvi(mi, vi(2, 0)));
    DP[0][0][1] = 1;
//    rep(i, N) DP[i][0] = 1;
//    rep(i, mi) DP[0][i] = 1;
    rep(i, N) {
        rep(j, mi) {
            FOR(k, j, min(mi,j + A[i] + 1)) {
                DP[i + 1][k][0] = add(DP[i + 1][k][0], DP[i][j][0]);
                if (k == j + A[i]) {
                    DP[i + 1][k][0] = add(DP[i + 1][k][0], DP[i][j][1]);
                } else {
                    DP[i + 1][k][1] = add(DP[i + 1][k][1], DP[i][j][1]);
                }
            }
        }
    }
    int ans = 0;
    rep(i, mi) {
        ans = add(ans, DP[N][i][0]);
    }
    cout << add(ans, DP[N][mi - 1][1]) << endl;

    return 0;
}

