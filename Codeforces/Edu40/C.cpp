// finish date: 2018/03/23

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


int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int dif = 1;
    rep(i, n - 1) {
        dif = max(dif, abs(a[i + 1] - a[i]));
    }
    rep(i, n - 1) {
        if (abs((a[i + 1] - 1) / dif - (a[i] - 1) / dif) + abs((a[i + 1] - 1) % dif - (a[i] - 1) % dif) != 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    cout << 1000000000 << " " << dif << endl;

    return 0;
}