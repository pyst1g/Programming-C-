// finish date: 2018/06/06
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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    int N, D;
    cin >> N >> D;
    vi X(N);
    rep(i, N) cin >> X[i];
    vi countJID(N, 0);
    rep(i, N) {
        countJID[i] = distance(X.begin(), lower_bound(X.begin(), X.end(), X[i] - D));
    }
    vi countKJD(N, 0);
    rep(i, N) {
        countKJD[i] = distance(upper_bound(X.begin(), X.end(), X[i] + D), X.end());
    }
    vi countKID(N, 0);
    rep(i, N) {
        countKID[i] = max((int) distance(X.begin(), upper_bound(X.begin(), X.end(), X[i] + D)) - i - 2, 0);
    }
    ll minus = 0;
    rep(i, N) {
        minus += (ll) countJID[i] * (N - (i + 1));
        minus += (ll) countKJD[i] * i;
        minus += (ll) countKID[i] * (countKID[i] + 1) / 2;
        minus -= (ll)countJID[i] * countKJD[i];
    }
    ll ans = (ll) N * (N - 1) * (N - 2) / 6 - minus;
    cout << ans << endl;
    return 0;
}



