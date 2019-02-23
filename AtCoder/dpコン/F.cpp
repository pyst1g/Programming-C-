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


int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vvi dp(n + 1, vi(m + 1, 0));
    FOR(i, 1, n + 1) {
        FOR(j, 1, m + 1) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (s[i - 1] == t[j - 1])});
        }
    }
//    cout<<dp[n][m]<<endl;
    string ans = "";
    int i = n, j = m;
    while (dp[i][j] != 0) {
        if (s[i-1]==t[j-1]) {
            i--, j--;
            ans = s[i] + ans;
        } else if (dp[i - 1][j] == dp[i][j]) i--;
        else j--;
    }
    cout << ans << endl;
    return 0;
}
