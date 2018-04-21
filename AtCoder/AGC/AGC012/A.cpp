// finish date: 2018/04/13

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
    int N;
    cin >> N;
    vi a(3 * N);
    rep(i, 3 * N) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    int c = 0;
    for (int i = 3 * N - 2; i > 0; i -= 2) {
        ans += a[i];
        c++;
        if (c >= N) break;
    }
    cout << ans << endl;

    return 0;
}