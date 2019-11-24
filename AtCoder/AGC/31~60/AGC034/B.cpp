// finish date: 2019/06/04

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
const int bigmod = 998244353;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    string s;
    cin >> s;
    int N = s.length();
    reverse(s.begin(), s.end());
    s = s + "#";
    ll ans = 0;
    int cntCB = 0;
    rep(i, N) {
        if (s[i] == 'A') {
            ans += cntCB;
        } else if (s[i] == 'B') {
            cntCB = 0;
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'B') {
                cntCB++;
                i++;
            } else {
                cntCB = 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
