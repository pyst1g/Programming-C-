// finish date: 2018/02/09

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

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
    vi H(N), S(N);
    rep(i, N) cin >> H[i] >> S[i];
    ll l = 0, r = LONG_LONG_MAX;
    ll m = (l + r) / 2;
    ll ans=0; //この0は適当
    while (l <= r) {
        m = (l + r) / 2;
        vi limit(N, 0);
        rep(i, N) {
            if(m-H[i]<0) goto out;
            ll x = (m - H[i]) / S[i];
//            if (x < 0) {
//                goto out;
//            }
            limit[(x <= N - 1) ? (unsigned int) x : N - 1]++;
        }
        for (int i = N - 2; i >= 0; i--) {
            limit[i] += limit[i + 1];
        }
        for (int i = N - 1; i >= 0; i--) {
            if (limit[i] < N - i) {
                goto out;
            }
        }
        //スコアm以内に収められる場合
        ans = m;
        r = m - 1;
        continue;

        //スコアm以内に収められなかった場合
        out:;
        l = m + 1;
    }
    cout << ans << endl;


    return 0;
}


