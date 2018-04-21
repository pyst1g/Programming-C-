// finish date: 2018/04/21

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll double
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
    ll C;
    cin >> N >> C;
    vl x(N);
    vl v(N);
    rep(i, N) {
        cin >> x[i] >> v[i];
    }
    vl ruiseki1(N), ruiseki2(N);
    rep(i, N) {
        ruiseki1[i] = v[i];
        if (i != 0) ruiseki1[i] += ruiseki1[i - 1];
    }
    for (int i = N - 1; i >= 0; i--) {
        ruiseki2[i] = v[i];
        if (i != N - 1) ruiseki2[i] += ruiseki2[i + 1];
    }
    vl max1(N), max2(N);
    rep(i, N) {
        if (i == 0) max1[i] = ruiseki1[i] - x[i];
        else max1[i] = max(max1[i - 1], ruiseki1[i] - x[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) max2[i] = ruiseki2[i] - (C - x[i]);
        else max2[i] = max(max2[i + 1], ruiseki2[i] - (C - x[i]));
    }

    ll ans = 0;
    rep(i, N) {
        //先に時計回り
        ll temp = ruiseki1[i] - x[i];
        if (i != N - 1) temp += max((ll) 0, max2[i + 1] - x[i]);
        ans = max(ans, temp);

        //先に反時計回り
        temp = ruiseki2[i] - (C - x[i]);
        if (i != 0) temp += max((ll) 0, max1[i - 1] - (C - x[i]));
        ans = max(ans, temp);
    }
    printf("%.0f\n", ans);



    return 0;
}