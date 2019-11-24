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
    ll A, B, X;
    cin >> A >> B >> X;
    ll mid = X / 2;
    int ma = 0;
    int left = 0;
    int right = 1000000000;

    while (left <= right) {
        mid = (left + right) / 2;
        if (A * mid + B * (ll(log10(mid)) + 1) <= X) {
            ma = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ma << endl;

    return 0;
}
