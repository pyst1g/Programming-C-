// finish date: 2018/03/14

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
    int N;
    cin >> N;
    vi p(N);
    rep(i, N) cin >> p[i];
    vi a(N), b(N);
    rep(i, N) {
        a[i] = 30000 * (i + 1);
        b[i] = 30000 * (N - i);
    }
    rep(i, N) {
        b[p[i] - 1] += i;
    }
    rep(i, N) cout << a[i] << " ";
    cout << endl;
    rep(i, N) cout << b[i] << " ";
    cout << endl;

    return 0;
}