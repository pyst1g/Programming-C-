// finish date: 2018/06/16
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

ll solve(vvl xyz, vi sign, int M) {
    vl S(xyz.size());
    rep(i, S.size()) {
        S[i] = xyz[i][0] * sign[0] + xyz[i][1] * sign[1] + xyz[i][2] * sign[2];
    }
    sort(S.begin(), S.end(),greater<ll>());
    ll ans = 0;
    rep(i, M) {
        ans += S[i];
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vvl xyz(N, vl(3, 0));
    rep(i, N) {
        cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
    }
    ll ma = solve(xyz, {1, 1, 1}, M);
    ma = max(ma,solve(xyz,{1,1,-1},M));
    ma = max(ma,solve(xyz,{1,-1,1},M));
    ma = max(ma,solve(xyz,{1,-1,-1},M));
    ma = max(ma,solve(xyz,{-1,1,1},M));
    ma = max(ma,solve(xyz,{-1,1,-1},M));
    ma = max(ma,solve(xyz,{-1,-1,1},M));
    ma = max(ma,solve(xyz,{-1,-1,-1},M));
    cout << ma << endl;

    return 0;
}




