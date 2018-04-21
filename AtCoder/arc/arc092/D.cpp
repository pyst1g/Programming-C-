// finish date: 2018/03/16

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
    vi a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    vi digit0(29, 0);
    vi digit1(29, 0);
    rep(i, N) {
        rep(j, digit0.size()) {
            digit0[j] += !(b[i] >> j & 1);
            digit1[j] += (b[i] >> j & 1);
        }
    }
    vl X(29, 0);

    rep(i, N) {
        rep(j, digit0.size()) {
            if (a[i] >> j & 1) {
                X[j] += digit0[i];

            } else {
                X[j] += digit1[i];
            }
        }
    }


    return 0;
}

