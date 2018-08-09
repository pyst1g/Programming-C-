// finish date: 2018/01/27
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
#define vb vector<bool>5
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 2000000000

void calcDistance(vvi &D, vector<vector<char>> graph, int sx, int sy, int m) {
    queue<pair<int, int>> s;
    s.push(make_pair(sx, sy));
    vi dx = {0, 1, 0, -1};
    vi dy = {1, 0, -1, 0};
    int mx, my, cost;
    pair<int, int> pos;
    while (!s.empty()) {
        pos = s.front();
        s.pop();
        rep(i, 4) {
            mx = pos.first + dx[i];
            my = pos.second + dy[i];
            if (!(0 <= mx && mx < D.size() && 0 <= my && my < D[0].size())) continue;
            cost = (graph[mx][my] == '#') ? m : 1;
            if ((ll)D[pos.first][pos.second] + cost < D[mx][my]) {
                D[mx][my] = D[pos.first][pos.second] + cost;
                s.push(make_pair(mx, my));
            }
        }
    }
}

int main() {
    int H, W, T;
    cin >> H >> W >> T;
    vector<vector<char>> s(H, vector<char>(W));
    //vvi d(H, vi(W, INF));
    int sx, sy, gx, gy;
    rep(i, H) {
        rep(j, W) {
            cin >> s[i][j];
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (s[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }

    int l = 0, r = (int) (pow(10, 9)+0.5);
    int m;
    int distance;
    int ans = -1;
    while (l <= r) {
        vvi d = vvi(H, vi(W, INF));
        d[sx][sy] = 0;
        m = (l + r) / 2;
        calcDistance(d, s, sx, sy, m);
        distance = d[gx][gy];
        if (distance <= T) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
        vvi().swap(d);
    }
    cout << ans << endl;

    return 0;
}

