// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <limits>
using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int main() {
    int R, C, sy, sx, gy, gx;
    char ch;
    vector<vector<int>> c;
    stack<int> stackY, stackX;
    cin >> R >> C >> sy >> sx >> gy >> gx;
    c.assign(R, vector<int>(C));
    rep(i, R) {
        rep(j, C) {
            cin >> ch;
            if (ch == '#') c[i][j] = -1;
            else c[i][j] = INT32_MAX;
        }
    }
    stackY.push(sy - 1);
    stackX.push(sx - 1);
    c[sy-1][sx-1] = 0;
    int cy, cx;
    int a, b;
    while (!stackY.empty()) {
        cy = stackY.top();
        stackY.pop();
        cx = stackX.top();
        stackX.pop();
        rep(i, 4) {
            //a,bは上下左右の座標の差(説明が下手でｺﾞﾒﾝ)
            if (i == 0) {
                a = 1;
                b = 0;
            } else if (i == 1) {
                a = -1;
                b = 0;
            } else if (i == 2) {
                a = 0;
                b = 1;
            } else {
                a = 0;
                b = -1;
            }

            if (c[cy + a][cx + b] >= 0 && c[cy][cx] + 1 < c[cy + a][cx + b]) {
                c[cy + a][cx + b] = c[cy][cx] + 1;
                stackY.push(cy + a);
                stackX.push(cx + b);
            }
        }
    }
    cout << c[gy - 1][gx - 1] << endl;
    return 0;
}
