// finish date: 2018/04/09

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
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    int mi = INF;
    ll sum = 0;
    rep(i, N) {
        sum += A[i];
        if (A[i] > B[i]) mi = min(mi, B[i]);
    }
    if (mi == INF) cout << 0 << endl;
    else cout << sum - mi << endl;

    return 0;
}