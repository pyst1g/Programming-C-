// finish date: 2018/03/04

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

vi memo;
int D;
map<int, pii > mp;

int memo_dfs(int i) {
    if (i - D <= 0) {
        memo[i] = 0;
        return 0;
    }
    if (memo[i] != INF) return memo[i];
    pii pair1 = mp[i];
    pii pair2 = mp[i - D];
    memo[i] = abs(pair1.first - pair2.first) + abs(pair1.second - pair2.second);
    memo[i] += memo_dfs(i - D);
    return memo[i];
}


int main() {
    int H, W;
    cin >> H >> W >> D;
    memo = vi(H * W + 1, INF);

    int in;
    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            cin >> in;
            mp[in] = pii(i, j);
        }
    }
    rep(i, H * W + 1) {
        memo_dfs(i);
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        int sum = 0;
        int L, R;
        cin >> L >> R;

        cout << memo[R] - memo[L] << endl;
    }
    return 0;
}



