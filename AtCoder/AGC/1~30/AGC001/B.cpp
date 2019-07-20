
// finish date: 2018/07/22
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


ll solve(ll a, ll b) {
    if (b == 0) return 0;
    if (a == b) return a;
    return 2 * ((a - 1) / b) * b + solve(b, a - ((a - 1) / b)*b);
}

int main() {
    ll N, X;
    cin >> N >> X;
    ll ans = N;
    ans += solve(max(X, N - X), min(X, N - X));
    cout << ans << endl;
    return 0;
}

