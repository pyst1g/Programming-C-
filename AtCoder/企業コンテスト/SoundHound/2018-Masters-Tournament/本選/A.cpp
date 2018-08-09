
// finish date: 2018/07/28
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
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    ll C, D;
    cin >> C >> D;
    ll s = 140, g = 170;
    ll cnt = 0;
    while (s < round(pow(10, 16))) {
        if (C <= s && g <= D) cnt += g - s;
        else if (C <= s && s < D && D <= g) cnt += D - s;
        else if (D >= g && s <= C && C < g) cnt += g - C;
        else if (s <= C && D <= g) cnt += D - C;
        s *= 2;
        g *= 2;
    }
    cout << cnt << endl;

    return 0;
}



