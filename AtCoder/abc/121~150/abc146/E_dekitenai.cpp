// finish date: 2019/11/24

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
const int INF = 1000000007;
const long long INFll = 100000000000000000;


int main() {
    int N, K;
    cin >> N >> K;
    vi A(N);
    rep(i, N) {
        cin >> A[i];
        A[i] -= 1;
        A[i] %= K;
    }
    vi cum(N, 0);
    rep(i, N) {
        cum[i] = A[i] % K;
        if (i != 0) cum[i] = (cum[i] + cum[i - 1]) % K;
    }
    ll ans = 0;
    map<int, int> cnt;
    rep(i, N) {
//        cum[i] = (K - cum[i]) % K;
        cnt[cum[i]]++;
    }
    rep(i, K-1) {
        if (cum[i] == 0) ans++;
    }

    int tmp = 0;
    rep(i, N) {
        cnt[cum[i]]--;
        tmp = (tmp + A[i]) % K;
        ans += cnt[tmp];
    }
    cout << ans << endl;

    return 0;
}
