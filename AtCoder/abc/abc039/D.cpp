// finish date: 2018/01/28
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
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

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
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define bigmod 1000000007
#define INF 1050000000



void around9(vs v, int i, int j, vs &ans, vs &temp) {
    vector<pair<int, int>> xy;
    xy.push_back(make_pair(i,j));
    if (j > 0) xy.push_back(make_pair(i, j - 1));
    if (j + 1 < v[0].size()) xy.push_back(make_pair(i, j + 1));
    if (i > 0) {
        xy.push_back(make_pair(i - 1, j));
        if (j > 0) xy.push_back(make_pair(i - 1, j - 1));
        if (j + 1 < v[0].size()) xy.push_back(make_pair(i - 1, j + 1));
    }
    if (i + 1 < v.size()) {
        xy.push_back(make_pair(i + 1, j));
        if (j > 0) xy.push_back(make_pair(i + 1, j - 1));
        if (j + 1 < v[0].size()) xy.push_back(make_pair(i + 1, j + 1));
    }

    //ここからやりたい処理を書く
    for (auto p: xy) if (v[p.first][p.second] != '#') return;
    ans[i][j] = '#';
    for (auto p:xy) temp[p.first][p.second] = '#';
}


int main() {
    int H, W;
    cin >> H >> W;
    vs S(H), ans(H, ""), temp(H, "");
    rep(i, H) cin >> S[i];
    rep(i, H) {
        rep(j, W) {
            ans[i] += ".";
            temp[i] += ".";
        }
    }

    rep(i, H) {
        rep(j, W) {
            around9(S, i, j, ans, temp);
        }
    }

    rep(i, H) {
        if (S[i] != temp[i]) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    rep(i, H) {
        cout << ans[i] << endl;
    }

    return 0;
}

