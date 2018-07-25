// finish date: 2018/07/23
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
    int N;
    cin >> N;
    vi D(N);
    rep(i, N) cin >> D[i];
    sort(D.begin(), D.end());
    if (D[0] == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    FOR(s, 1, 13) {
        vb used(24, false);
        used[0] = true;
        rep(i, N) {
            bool flg = false;
            for (int j = -s + 1; j <= s - 1; j++) {
                if (used[(D[i] + j + 24) % 24]) {
                    flg = true;
                    break;
                }
                if (j == s - 1) used[D[i]] = true;
            }
            if (flg) {
                for (int j = -s + 1; j <= s - 1; j++) {
                    if (used[(-D[i] + j + 24) % 24]) {
                        cout << s - 1 << endl;
                        return 0;
                    }
                    if (j == s - 1) used[(24 - D[i]) % 24] = true;
                }
            }
        }
    }
    cout << 12 << endl;

    return 0;
}

