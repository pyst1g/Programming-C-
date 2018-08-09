// finish date: 2018/07/16
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


struct zahyou {
    int x, y;

    bool operator<(const zahyou &another) const {
        //メンバ変数であるnum1で比較した結果を
        //この構造体の比較とする
        return x < another.x;
    }

};

int main() {
    int N, K;
    cin >> N >> K;
    vi x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    int cnt;
    int cx1, cx2;
    int cy1, cy2;
    ll ans = LONG_LONG_MAX;
    rep(xi, N) {
        FOR(xj, xi + 1, N) {
            rep(yi, N) {
                FOR(yj, yi + 1, N) {
                    cnt = 0;
                    cx1 = min(x[xi], x[xj]);
                    cx2 = max(x[xi], x[xj]);
                    cy1 = min(y[yi], y[yj]);
                    cy2 = max(y[yi], y[yj]);
                    rep(i, N) {
                        if ((cx1 <= x[i] && x[i] <= cx2) && (cy1 <= y[i] && y[i] <= cy2)) cnt++;
                    }
                    if (cnt >= K) {
                        ans = min(ans, (ll) (cx2 - cx1) * (cy2 - cy1));
                    }
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}

