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
    vi X = a;
    sort(X.begin(), X.end());
    int val1 = X[N / 2 - 1];
    int val2 = X[N / 2];
    rep(i, N) {
        if (a[i] <= val1) cout << val2 << endl;
        else cout << val1 << endl;
    }

    return 0;
}