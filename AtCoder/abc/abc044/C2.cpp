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
    rep(i, N) cin >> x[i];
    ll dp[N + 1][50 * N + 1][N + 1];
    rep(i, N + 1) rep(j, 50 * N + 1) rep(k, N + 1) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    //sort(x.begin(), x.end());
    rep(i, N) {
        rep(j, 50 * i + 1) {
            rep(k, i + 1) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j + x[i]][k + 1] += dp[i][j][k];
            }
        }
    }

    ll ans=0;
    FOR(i,1,N+1){
        ans += dp[N][A*i][i];
    }
    cout<<ans<<endl;


    return 0;
}

