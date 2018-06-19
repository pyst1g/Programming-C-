// finish date: 2018/05/02
#include <bits/stdc++.h>


using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>

//最大公約数
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) {
        swap(a, b);
    }
    int r = 1; //0以外であれば何でも
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x, Vx, Vy;
    map<ll, int> mp;
    map<pii, int> dup;
    rep(i, n) {
        cin >> x >> Vx >> Vy;
        mp[(ll) a * Vx - Vy]++;
        dup[pii(Vx, Vy)]++;
    }
    ll ans = 0;

    for (auto entry:mp) {
        ans += (ll) entry.second * (entry.second - 1);
    }
    for (auto entry:dup) {
        ans -= (ll) entry.second * (entry.second - 1);
    }
    cout << ans << endl;


    return 0;
}