// finish date: 2018/06/17
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

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
    ll A, B;
    cin >> A >> B;
    int N = (int) (B - A + 1);
    vl AB(N);
    rep(i, B - A + 1) AB[i] = A + i;
    vi prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int pNum = 11;
    vi dp(1 << 11, 0);
    dp[0] = 1;
    rep(i, N) {
        int st = 0;
        rep(j, 11) if (AB[i] % prime[j] == 0) st += 1 << j;
        rep(j, 1 << 11) {
            if (dp[j] == 0) continue;
            if ((j & st) == 0) dp[j | st] += dp[j];
        }
    }
    int sum = 0;
    rep(i, 1 << 11) {
        sum += dp[i];
    }
    cout << sum << endl;

    return 0;
}




