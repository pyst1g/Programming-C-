// finish date: 2018/01/27
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
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 1050000000


int main() {
    int N, A;
    cin >> N >> A;
    vi x(N);
    rep(i, N) {
        cin >> x[i];
        x[i] -= A;
    }
    vvl DP(N + 1, vl(5001, 0));
    DP[0][DP[0].size() / 2] = 1;
    rep(i, N) {
        rep(j, 5001) {
            DP[i + 1][j] += DP[i][j];
            DP[i + 1][j + x[i]] += DP[i][j];
        }
    }
    cout << DP[N][DP[0].size() / 2] - 1 << endl;

    return 0;
}

