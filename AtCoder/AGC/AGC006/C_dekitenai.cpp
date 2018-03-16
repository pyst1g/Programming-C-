// finish date: 2018/03/14

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
    vl x(N);
    rep(i, N) cin >> x[i];
    int M;
    ll K;
    cin >> M >> K;
    vi a(M);
    rep(i, M) {
        cin >> a[i];
        a[i]--;
    }
    vvl T(62, vl(N, 0));
    rep(k, 62) {
        rep(i, M) {
            x[a[i]] = x[a[i] + 1] + x[a[i] - 1] - x[a[i]];
        }
        rep(i, N) {
            T[k][i] = x[i];
        }
    }

    vl ans(N, 0);
    rep(k, 62) {
        if ((K >> k) & 1) {
            rep(i, N) {
                ans[i] += T[k][i];
            }
        }
    }

    rep(i,N) cout<<ans[i]<<endl;


    return 0;
}