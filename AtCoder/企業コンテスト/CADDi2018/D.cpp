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
    //入力と変数宣言
    int N;
    cin >> N;
    vi a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    map<int, int> mp;
    rep(i, N) {
        mp[a[i]]++;
    }
    vi stk;
    vi stk_val;
    for (auto e = mp.rbegin(); e != mp.rend(); e++) {
        stk.push_back(e->second);
        stk_val.push_back(e->first);
    }

    vi tower(N + 1, 0);
    int tmp = 0;
    rep(i, stk.size() - 1) {
        tmp += stk[i];
        tower[tmp] = stk_val[i] - stk_val[i + 1];
    }
    tower[N] = stk_val[stk_val.size() - 1];

    int nim = 0;
    rep(i, N + 1) {
        if (tower[i] % 2 == 1) {
            nim ^= i;
        }
    }
    if (nim != 0) cout << "first" << endl;
    else cout << "second" << endl;

    return 0;
}

