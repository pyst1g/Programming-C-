// finish date: 2018/04/28

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll double
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
    vl A(N);
    rep(i, N) cin >> A[i];
    vl ruiseki(N, 0);
    map<ll, int> mp;
    rep(i, N) {
        ruiseki[i] = A[i];
        if (i > 0) ruiseki[i] += ruiseki[i - 1];
        mp[ruiseki[i]]++;
    }
    ll ans = 0;
    for (auto entry:mp) {
        ans += (ll) entry.second * (entry.second - 1) / 2;
    }
    ans += mp[0];
    printf("%.0f\n", ans);
    //cout << ans << endl;

    return 0;
}