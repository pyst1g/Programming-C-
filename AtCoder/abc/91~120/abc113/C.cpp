// finish date: 2018/11/9

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


struct PY {
    int p, y;

    bool operator<(const PY &another) const {
        //メンバ変数であるnum1で比較した結果を
        //この構造体の比較とする
        return y < another.y;
    }

};

string to6(int n) {
    string str = to_string(n);
    while (str.length() != 6) {
        str = '0' + str;
    }
    return str;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<PY> py(M);
    rep(i, M) {
        int p, y;
        cin >> p >> y;
        py[i].p = p;
        py[i].y = y;
    }
    vector<PY> py2 = py;
    sort(py2.begin(), py2.end());
    vi num(N + 1, 0);
    map<PY, int> mp;
    rep(i, M) mp[py2[i]] = ++num[py2[i].p];
    rep(i, M) cout << to6(py[i].p) << to6(mp[py[i]]) << endl;

    return 0;
}

