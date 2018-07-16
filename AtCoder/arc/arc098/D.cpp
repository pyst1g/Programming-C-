// finish date: 2018/05/26

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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    vi bcount(20, 0);
    int l = 0;
    int r = 0;
    rep(i, 20) bcount[i] += (A[r] >> i) % 2;
    while (r < N) {
        rep(i, 20) {
            if (bcount[i] > 1) {
                rep(j, 20) bcount[j] -= (A[l] >> j) % 2;
                l++;
                goto outer;
            }
        }
        ans += r - l;
        r++;
        rep(i, 20) bcount[i] += (A[r] >> i) % 2;
        outer:;
    }
    cout << ans + N << endl;


    return 0;
}


