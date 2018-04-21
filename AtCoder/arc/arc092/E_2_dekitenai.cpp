// finish date: 2018/04/10

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
    vl ruiseki(N, 0);
    for (int i = 0; i < N; i += 2) {
        ruiseki[i] += a[i];
        if (i - 2 >= 0) ruiseki[i] += ruiseki[i - 2];
    }
    for (int i = 1; i < N; i += 2) {
        ruiseki[i] += a[i];
        if (i - 2 >= 0) ruiseki[i] += ruiseki[i - 2];
    }
    for (int i = 0; i < N; i += 2) {
        ruiseki[i] += a[i];
        if (i - 2 >= 0) ruiseki[i] += ruiseki[i - 2];
    }
    int maxI = INF, maxJ = INF;
    ll ma = -LONG_LONG_MAX;
    for (int i = 1; i < N; i += 2) {
        for (int j = i; j < N; j += 2) {
            if (ruiseki[j] - ruiseki[i] + a[i] > ma) {
                ma = ruiseki[j] - ruiseki[i];
                maxI = i;
                maxJ = j;
            }
        }
    }
    if (ma < 0) {
        FOR(i, 1, maxI + 1) {
            cout << 0 << endl;
        }
        FOR(i, 1, N - maxI) {
            cout << N - maxI - i << endl;
        }
    } else {

    }
    //全部マイナスの時の処理も書く
    return 0;
}
