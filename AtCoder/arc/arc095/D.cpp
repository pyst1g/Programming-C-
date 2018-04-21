// finish date: 2018/04/15

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
    vi a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    double half = a[N - 1] / 2.0;
    double mi = INF;
    int miIndex = 0;
    rep(i, N - 1) {
        if (abs(half - a[i]) < mi) {
            mi = abs(half - a[i]);
            miIndex = i;
        }
    }
    cout << a[N - 1] << " " << a[miIndex] << endl;

    return 0;
}