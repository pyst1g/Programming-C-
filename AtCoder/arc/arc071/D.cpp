// finish date: 2018/07/16
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


//足し算
int add(int a, int b) {
    return (int)(((ll)a + b + bigmod) % bigmod);
}

//引き算
int sub(int a, int b) {
    return (int)(((ll)a - b + bigmod) % bigmod);
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int makeSum(vi a) {
    int ans = 0;
    int n = a.size();
    rep(i, n) {
        ans = add(ans, mul(a[i], i + 1));
        ans = sub(ans, mul(a[i], n - i));
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vi x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    cout << mul(makeSum(x), makeSum(y)) << endl;

    return 0;
}

