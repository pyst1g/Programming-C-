// finish date: 2018/2/05

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
    int n;
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    vvi dp(n, vi(n, 0));
    map<int, int> mp;
    int ma = 2;

    rep(i, n) mp[v[i]] = i;
    rep(i, n) dp[0][i] = 2;

    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            if (mp.count(2 * v[i] - v[j])) {
                dp[i][j] = dp[mp[2 * v[i] - v[j]]][i] + 1;
            } else {
                dp[i][j] = 2;
            }
            ma = max(ma, dp[i][j]);
        }
    }

    cout << ma << endl;
    return 0;
}