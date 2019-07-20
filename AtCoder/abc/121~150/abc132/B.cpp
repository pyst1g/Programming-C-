// finish date: 2019/06/29

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
const int bigmod = 998244353;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    int n;
    cin >> n;

    vi p(n);
    rep(i, n) {
        cin >> p[i];
    }
    int cnt = 0;
    FOR(i, 1, n - 1) {
        if ((p[i - 1] < p[i] && p[i] <= p[i + 1]) || (p[i + 1] < p[i] && p[i] <= p[i - 1])) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
