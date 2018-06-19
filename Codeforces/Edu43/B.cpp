// finish date: 2018/04/30

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
    ll n, m;
    ll k;
    cin >> n >> m >> k;
    if (k < n) {
        cout << k + 1 << " " << 1 << endl;
        return 0;
    }
    k -= n;
    m--;
    int a = (int) (k / m);
    int b = (int) (k % m);
    if (a % 2 == 1) b = m - b -1;
    cout << n - a << " " << b + 2 << endl;

    return 0;
}