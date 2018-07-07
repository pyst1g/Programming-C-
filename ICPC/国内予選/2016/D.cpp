// finish date: 2018/07/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<long double> vd;
typedef vector<vector<long double>> vvd;
typedef vector<vector<vector<long double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    int n;

    while(true) {
        cin >> n;
        if(n == 0) {
            break;
        }

        vi w(n);
        rep(i, n) {
            cin >> w[i];
        }

        vvi dp(n + 1, vi(n + 1, 0));

        rep(i, n - 1) {
            dp[i][i + 1] = (abs(w[i] - w[i + 1]) <= 1) ? 2 : 0;
        }

        FOR(k, 2, n) {
            rep(i, n) {
                int j=i+k;
                if(j >= n) {
                    continue;
                }
                if(abs(w[i] - w[j]) <=1 && dp[i + 1][j - 1] == (j - 1) - (i + 1) +1) {
                    dp[i][j] = j - i + 1;
                } else {
                    FOR(l, i, j) {
                        dp[i][j] = max(dp[i][j], dp[i][l] + dp[l + 1][j]);
                    }
                }
            }
        }

        cout << dp[0][n-1] << endl;
    }

    return 0;
}
