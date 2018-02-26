// finish date: 2018/02/11

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
    int N, A, B;
    cin >> N >> A >> B;
    vi h(N);
    rep(i, N) cin >> h[i];
    int l = 1, r = 1e9;
    int m;
    ll c;
    ll life;
    int ans = 0;
    while (l <= r) {
        c = 0;
        m = (l + r) / 2;
        rep(i, N) {
            life = (ll)h[i] - (ll)m * B;
            if (life > 0) {
                c += (life + (A - B) - 1) / (A - B);
            }
        }
        if (c <= m) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << endl;

    return 0;
}


