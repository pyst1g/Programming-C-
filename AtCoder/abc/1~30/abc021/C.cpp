// finish date: 2018/02/04

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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    int N, a, b, M;
    cin >> N >> a >> b >> M;
    a--;
    b--;
    int x, y;
    vvi path(N, vi(N, INF));
    rep(i, N) path[i][i] = 0;
    rep(i, M) {
        cin >> x >> y;
        x--;
        y--;
        path[x][y] = 1;
        path[y][x] = 1;
    }
    //ワーシャルフロイド
    rep(k, N)rep(i, N)rep(j, N) path[i][j] = min(path[i][j], path[i][k] + path[k][j]);

    //aからbの最短経路上の頂点iからbまでの距離の経路数を格納
    // (disCount[1]=2 はiからbまでの距離が1である経路数が2つあることを示す)
    vi disCount(path[a][b] + 1, 0);
    rep(i, N) if (path[a][i] + path[i][b] == path[a][b]) disCount[path[i][b]]++;

    int ans = 1;
    rep(i, disCount.size()) ans = mul(ans, disCount[i]);
    cout << ans << endl;

    return 0;

}

