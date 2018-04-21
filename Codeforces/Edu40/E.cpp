// finish date: 2018/03/22

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
//
//double calc_temperature() {
//    if (==0) return 0;
//}

int main() {
    int n, T;
    cin >> n >> T;
    vi a(n), t(n);
    ll sumX = 0;
    ll sumXT = 0;
    rep(i, n) {
        cin >> a[i];
        sumX += a[i];
    }
    rep(i, n) {
        cin >> t[i];
        sumXT += (ll) a[i] * t[i];
    }
    map<ll, ll> underT, overT;
    ll just = 0;
    rep(i, n) {
        if (t[i] < T) underT[t[i]] += a[i];
        else if (t[i] > T) overT[t[i]] += a[i];
        else just += a[i];
    }

    double temp = (double) sumXT / sumX;
    while (true) {
        if (temp == T) {
            cout << sumX << endl;
            return 0;
        } else if (temp < T) {
            if (underT.empty()) break;
            ll xt = sumXT - (ll) underT.begin()->first * underT.begin()->second;
            ll x = sumX - underT.begin()->second;
            sumXT = xt;
            sumX = x;
            if (x == 0) break;
            double nexttemp = (double) xt / x;
            if (nexttemp > T) {
                printf("%.7f\n", (double) sumX + ((double) (sumXT - (ll) T * sumX) / (T - underT.begin()->first)));
                return 0;
            }
            temp = nexttemp;
            underT.erase(underT.begin()->first);
        } else {
            if (overT.empty()) break;
            ll xt = sumXT - (ll) overT.rbegin()->first * overT.rbegin()->second;
            ll x = sumX - overT.rbegin()->second;
            sumXT = xt;
            sumX = x;
            if (x == 0) break;
            double nexttemp = (double) xt / x;
            if (nexttemp < T) {
                printf("%.7f\n", (double) sumX + ((double) (sumXT - (ll) T * sumX) / (T - overT.rbegin()->first)));
                return 0;
            }
            temp = nexttemp;
            overT.erase(overT.rbegin()->first);
        }
    }
    cout << 0 << endl;
    return 0;

    return 0;
}