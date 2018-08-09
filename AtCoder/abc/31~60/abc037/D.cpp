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


vvi a;
vvi path;
int H, W;

//足し算
int add(int a, int b) {
    return (a + b) % bigmod;
}

int memoization(int i, int j) {
    if (path[i][j] != 0) return path[i][j];
    path[i][j] = 1;
    vi y = {0, 1, 0, -1};
    vi x = {-1, 0, 1, 0};
    rep(k, 4) {
        if ((0 <= j + x[k] && j + x[k] < W) && (0 <= i + y[k] && i + y[k] < H)) {
            if (a[i + y[k]][j + x[k]] > a[i][j]) {
                path[i][j] = add(path[i][j], memoization(i + y[k], j + x[k]));
            }
        }
    }
    return path[i][j];
}

int main() {
    cin >> H >> W;
    a = vvi(H, vi(W));
    rep(i, H) rep(j, W) cin >> a[i][j];
    path = vvi(H, vi(W, 0));
    int sum = 0;
    //本処理
    rep(i, H) {
        rep(j, W) {
            memoization(i, j);
            sum = add(sum, path[i][j]);
        }
    }
    cout << sum << endl;


    return 0;

}

