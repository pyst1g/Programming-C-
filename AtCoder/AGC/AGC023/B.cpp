// finish date: 2018/04/28

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
    cin >> N;
    vs SS(N);
    rep(i, N) {
        cin >> SS[i];
    }
    int ans = 0;
    rep(k, N) {
        rep(i, N) {
            FOR(j, 1, N - i) {
                if (SS[(k + i) % N][(i + j) % N] != SS[(k + i + j) % N][i]) goto outer;
            }
        }
        ans += N;
        outer:;
    }
    cout << ans << endl;

    return 0;
}
