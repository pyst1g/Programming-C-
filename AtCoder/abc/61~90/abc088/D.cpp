// finish date: 2018/02/18

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


struct pos {
    int x, y;
};

int main() {
    int H, W;
    cin >> H >> W;
    vs s(H);
    rep(i, H) cin >> s[i];
    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '.') ans++;
        }
    }
    pos p;
    p.x = 0;
    p.y = 0;
    stack<pos> st;
    st.push(p);
    vvi dis(H, vi(W, INF));
    dis[0][0] = 0;
    while (!st.empty()) {
        p = st.top();
        st.pop();
        for (int i = -1; i <= 1; i += 2) {
            if (0 <= p.x + i && p.x + i < W) {
                if (s[p.y][p.x + i] == '.') {
                    if (dis[p.y][p.x] + 1 < dis[p.y][p.x + i]) {
                        dis[p.y][p.x + i] = dis[p.y][p.x] + 1;
                        p.x = p.x + i;
                        st.push(p);
                        p.x = p.x - i;
                    }
                }
            }
            if (0 <= p.y + i && p.y + i < H) {
                if (s[p.y + i][p.x] == '.') {
                    if (dis[p.y][p.x] + 1 < dis[p.y + i][p.x]) {
                        dis[p.y + i][p.x] = dis[p.y][p.x] + 1;
                        p.y = p.y + i;
                        st.push(p);
                        p.y = p.y - i;
                    }
                }
            }
        }
    }
    if (dis[H - 1][W - 1] == INF) cout << -1 << endl;
    else cout << ans - dis[H - 1][W - 1] - 1 << endl;


    return 0;
}


