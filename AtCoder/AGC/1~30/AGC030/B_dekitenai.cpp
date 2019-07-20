// finish date: 2018/12/22

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
const int INF = 10500000z00;
const long long INFll = 100000000000000000;


int main() {
    int L, N;
    cin >> L >> N;
    vl Xl(N), Xr(N);
    rep(i, N) {
        cin >> Xl[i];
        Xr[i] = L - Xl[i];
    }
    reverse(Xr.begin(), Xr.end());
    vl accXl = Xl, accXr = Xr;
    FOR(i, 1, N) {
        accXl[i] += accXl[i - 1];
        accXr[i] += accXr[i - 1];
    }
    //ll total_Acc = 2 * accXl[Xl.size() - 1];
    ll ans = max(Xl[Xl.size() - 1], Xr[Xr.size() - 1]);
    FOR(k, 1, N - 1) {
        ll temp = 2 * (accXl[k] + accXr[N - k - 2]);
        if (k + 1 > N - (k + 1)) {
            temp -= 2 * accXl[2 * (k + 1) - N - 1];
        } else if (N - (k + 1) > k + 1) {
            temp -= 2 * accXr[N - 2 * (k + 1) - 1];
        }
        temp -= min(Xl[k], Xr[N - k - 2]);
        ans = max(ans, temp);
    }
    cout << ans << endl;

    return 0;
}












// finish date: 2018/12/22

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
    int L, N;
    cin >> L >> N;
    vl Xl(N), Xr(N);
    rep(i, N) {
        cin >> Xl[i];
        Xr[i] = L - Xl[i];
    }
    reverse(Xr.begin(), Xr.end());
    vl accXl = Xl, accXr = Xr;
    FOR(i, 1, N) {
        accXl[i] += accXl[i - 1];
        accXr[i] += accXr[i - 1];
    }
    //ll total_Acc = 2 * accXl[Xl.size() - 1];
    ll ans = max(Xl[Xl.size() - 1], Xr[Xr.size() - 1]);
    FOR(k, 1, N - 1) {
        ll temp = 2 * (accXl[k] + accXr[N - k - 2]);
        if (k + 1 > N - (k + 1)) {
            ans = min(ans,temp - ((2 * (k + 1) - N - 2 >= 0) ? 2 * accXl[2 * (k + 1) - N - 2] : 0) + (L - Xl[k]));
            ans = min(ans,temp - 2 * accXl[2 * (k + 1) - N] + Xl[k]);
            temp += Xr[k];
        } else if (N - (k + 1) > k + 1) {
            temp -= 2 * accXr[N - 2 * (k + 1)];
            temp += Xr[N - k - 2];
        }
//        temp -= min(Xl[k], Xr[N - k - 2]);
        ans = max(ans, temp);
    }
    cout << ans << endl;

    return 0;
}


