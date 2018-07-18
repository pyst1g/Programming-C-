// finish date: 2018/07/18
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


int main() {
    string S;
    cin >> S;
    string checker = "";
    rep(i, S.size()) {
        if (S[i] != 'x') checker += S[i];
    }
    string cr = checker;
    reverse(cr.begin(), cr.end());
    if (checker != cr) {
        cout << -1 << endl;
        return 0;
    }
    vi cntX(checker.size() + 1, 0);
    int idx = 0;
    rep(i, S.size()) {
        if (S[i] == 'x') {
            cntX[idx]++;
        } else {
            idx++;
        }
    }
    int ans = 0;
    rep(i, (checker.size() + 1) / 2) {
        ans += abs(cntX[i] - cntX[cntX.size() - 1 - i]);
    }
    cout << ans << endl;

    return 0;
}



