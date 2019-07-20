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
    int N, K;
    cin >> N >> K;
    vi a(N);
    vl sum(N);
    vl positive_sum(N);
    rep(i, N) {
        cin >> a[i];
        sum[i] = a[i];
        positive_sum[i] = max(0, a[i]);
        if (i != 0) {
            sum[i] += sum[i - 1];
            positive_sum[i] += positive_sum[i - 1];
        }
    }

    ll ans = LONG_LONG_MIN;
    rep(i, N - K + 1) {
        ll sum1 = (i > 0) ? positive_sum[i - 1] : 0;
        ll sum2 = max((ll) 0, (i > 0) ? sum[i + K - 1] - sum[i - 1] : sum[i + K - 1]);
        ll sum3 = positive_sum[N - 1] - positive_sum[i + K - 1];
        ans = max(ans, sum1 + sum2 + sum3);
    }
    cout << ans << endl;


    return 0;
}