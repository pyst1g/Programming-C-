// finish date: 2018/07/03
//尺取り法を使用 O(N)
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<long double> vd;
typedef vector<vector<long double>> vvd;
typedef vector<vector<vector<long double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    vl acc(N, 0);
    rep(i, N) {
        acc[i] = A[i];
        if (i > 0) acc[i] += acc[i - 1];
    }
    ll ans = LONG_LONG_MAX;
    int posL = 0;
    int posR = 2;
    FOR(k, 1, N - 2) {
        ll sumL = acc[k];
        ll sumR = acc[N - 1] - acc[k];
//        while (posL <= k) posL++;
        while (posR <= k) posR++;
        while (abs(sumL / 2.0 - acc[posL]) >= abs(sumL / 2.0 - acc[posL + 1])) posL++;
        while (abs(sumR / 2.0 - (acc[posR] - sumL)) >= abs(sumR / 2.0 - (acc[posR + 1] - sumL))) posR++;
        ll sumB = acc[posL];
        ll sumC = sumL - sumB;
        ll sumD = acc[posR] - acc[k];
        ll sumE = sumR - sumD;

//        auto itr1 = upper_bound(acc.begin(), acc.end(), sumL / 2.0);
//        ll sumB = (abs(sumL - 2 * *itr1) < abs(sumL - 2 * *(itr1 - 1))) ? *(itr1) : *(itr1 - 1);
//        ll sumC = sumL - sumB;
//        auto itr2 = upper_bound(acc.begin(), acc.end(), sumL + sumR / 2.0);
//        ll sumD = (abs(acc[N] - 2 * *itr2) < abs(acc[N] - 2 * *(itr2 - 1))) ? *(itr2) - sumL : *(itr2 - 1) - sumL;
//        ll sumE = sumR - sumD;
        ans = min(ans, max({sumB, sumC, sumD, sumE}) - min({sumB, sumC, sumD, sumE}));
    }
    cout << ans << endl;

    return 0;
}
