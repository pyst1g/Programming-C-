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


//素因数分解
map<ll, ll> p_fact(ll n) {
    map<ll, ll> mp;
    ll i = 2;
    while (n >= i * i) {
        while (n % i == 0) mp[i]++, n /= i;
        i++;
    }
    if (n != 1) mp[n]++;
    return mp;
}


int main() {
    //入力と変数宣言
    ll N, P;
    cin >> N >> P;

    ll ans = 1;
    map<ll, ll> mp = p_fact(P);
    for (auto e:mp) {
        while (e.second >= N) {
            ans *= e.first;
            e.second -= N;
        }
    }
    cout << ans << endl;

    return 0;
}

