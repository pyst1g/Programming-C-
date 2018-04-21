// finish date: 2018/04/17

#include <bits/stdc++.h>

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
    int n, A, B, C, T;
    cin >> n >> A >> B >> C >> T;
    vi t(n);
    rep(i, n) cin >> t[i];
    ll ans = 0;
    rep(i, n) {
        ans += A + max((T - t[i]) * (C - B), 0);
    }
    cout << ans << endl;

    return 0;
}