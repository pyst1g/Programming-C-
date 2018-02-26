// finish date: 2018/02/02
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;


int main() {
    int N, W;
    cin >> N >> W;
    vvl DP(N + 1, vl(302, 0));
    int w, v;
    int w1;
    ll ma = 0;
    rep(i, N) {
        cin >> w >> v;
        if (i == 0) w1 = w;
        w -= w1;
        for (int j = i + 1; j >= 0; j--) {
            rep(k, DP[j].size()) {
                if (DP[j][k] > 0 || (j == 0 && k == 0)) {
                    DP[j + 1][k + w] = max(DP[j + 1][k + w], DP[j][k] + v);
                    if ((ll)(j + 1) * w1 + (k + w) <= W) ma = max(ma, DP[j + 1][k + w]);
                }
            }
        }
    }
    cout << ma << endl;

    return 0;
}

