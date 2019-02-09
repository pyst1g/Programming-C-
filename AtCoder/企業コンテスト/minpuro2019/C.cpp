// finish date: 2018/2/09

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


int main() {
    int K, A, B;
    cin >> K >> A >> B;
    ll ans = 1;
    if (1 + K <= A || B - A <= 2) {
        cout << 1 + K << endl;
        return 0;
    }
    //前処理
    int T = K;
    int last_add = 0;
    T -= A - 1;
    ans = A;
    if (T % 2) last_add = 1;

    T /= 2;
    ans+= (ll) T * (B - A);

    ans += last_add;
    cout << ans << endl;
    return 0;
}
