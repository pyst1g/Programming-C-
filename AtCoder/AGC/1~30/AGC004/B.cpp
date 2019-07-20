// finish date: 2018/03/09

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
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>


int main() {
    int N, x;
    cin >> N >> x;
    vi a(N);
    rep(i, N) cin >> a[i];
    vvi b(N, vi(N));
    ll ans = 0;
    rep(i, N) {
        b[0][i] = a[i];
        ans += a[i];
    }
    FOR (i, 1, N) {
        ll temp = 0;
        rep(j, N) {
            b[i][j] = min(b[i - 1][(j - 1 + N) % N], a[j]);
            temp += b[i][j];
        }
        ans = min(ans, temp + (ll) x * i);
    }
    cout << ans << endl;

    return 0;
}