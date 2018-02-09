// finish date: 2018/02/05

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
#define pii pair<int,int>

int W, H, N;
vvi XY;
map<pair<pii, pii >, int> getGold;

int memoization(int bx, int by, int tx, int ty) {
    //if (bx == tx || by == ty) return 0;
    if (getGold.count(pair<pii, pii >(pii(bx, by), pii(tx, ty))) != 0) {
        return getGold[pair<pii, pii >(pii(bx, by), pii(tx, ty))];
    }
    int ans = 0;
    int temp;
    rep(i, N) {
        temp = 0;
        if ((bx <= XY[i][0] && XY[i][0] <= tx) && (by <= XY[i][1] && XY[i][1] <= ty)) {
            temp += (tx - bx + 1) + (ty - by + 1) - 1;
            if ((0 <= XY[i][0] - 1 && XY[i][0] - 1 < W) && (0 <= XY[i][1] - 1 && XY[i][1] - 1 < H)) {
                temp += memoization(bx, by, XY[i][0] - 1, XY[i][1] - 1);
            }
            if ((0 <= XY[i][0] - 1 && XY[i][0] - 1 < W) && (0 <= XY[i][1] + 1 && XY[i][1] + 1 < H)) {
                temp += memoization(bx, XY[i][1] + 1, XY[i][0] - 1, ty);
            }
            if ((0 <= XY[i][0] + 1 && XY[i][0] + 1 < W) && (0 <= XY[i][1] + 1 && XY[i][1] + 1 < H)) {
                temp += memoization(XY[i][0] + 1, XY[i][1] + 1, tx, ty);
            }
            if ((0 <= XY[i][0] + 1 && XY[i][0] + 1 < W) && (0 <= XY[i][1] - 1 && XY[i][1] - 1 < H)) {
                temp += memoization(XY[i][0] + 1, by, tx, XY[i][1] - 1);
            }
        }
        ans = max(ans,temp);
    }
    getGold[pair<pii, pii >(pii(bx, by), pii(tx, ty))] = ans;
    return ans;
}

int main() {
    cin >> W >> H >> N;
    XY = vvi(N, vi(2));
    rep(i, N) {
        cin >> XY[i][0] >> XY[i][1];
        XY[i][0]--;
        XY[i][1]--;
    }
    cout << memoization(0, 0, W - 1, H - 1) << endl;


    return 0;
}



