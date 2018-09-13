// finish date: 2018/08/13
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>>
        vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>>
        vvvd;
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


int main() {
    int N, M;
    cin >> N >> M;
    vi A(N + 1);
    A[0] = 0;
    FOR(i, 1, N + 1) cin >> A[i];
    ll ans = 0;
    map<int, int> mp;
    mp[0]++;
    FOR(i, 1, N+1) {
        A[i] = (A[i - 1] + A[i]) % M;
        mp[A[i]]++;
    }
    for (auto e:mp) {
        int num = e.second;
        ans += ((ll) e.second * (e.second - 1)) / 2;
    }
    cout << ans << endl;


    return 0;
}

