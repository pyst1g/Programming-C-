// finish date: 2018/07/03
//二分探索を使用 O(NlogN)

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

    FOR(k, 1, N - 2) {
        auto itr1 = upper_bound(acc.begin(), acc.end(), acc[k] / 2.0);
        ll sumB = *itr1;
        if (distance(acc.begin(), itr1 - 1) >= 0) {
            if (abs(acc[k] / 2.0 - *itr1) > abs(acc[k] / 2.0 - *(itr1 - 1))) {
                sumB = *(itr1 - 1);
            }
        }
        ll sumC = acc[k] - sumB;

        auto itr2 = upper_bound(acc.begin(), acc.end(), acc[k] + (acc[N - 1] - acc[k]) / 2.0);
        ll sumD = *itr2 - acc[k];
        if (distance(acc.begin(), itr2 - 1) > k) {
            if (abs(acc[k] + (acc[N - 1] - acc[k]) / 2.0 - *itr2) >
                abs(acc[k] + (acc[N - 1] - acc[k]) / 2.0 - *(itr2 - 1))) {
                sumD = *(itr2 - 1) - acc[k];
            }
        }
        ll sumE = acc[N - 1] - sumD - acc[k];


        ans = min(ans, max({sumB, sumC, sumD, sumE}) - min({sumB, sumC, sumD, sumE}));
    }
    cout << ans << endl;

    return 0;
}

