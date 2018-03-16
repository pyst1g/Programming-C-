// finish date: 2018/03/10

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

void minusMapSecond(map<int, int> &mp, int key) {
    mp[key]--;
    if (mp[key] == 0) mp.erase(key);
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    int a;
    vvi ans(H, vi(W, 0));
    int x = -1, y = 0;
    FOR(i, 1, N + 1) {
        cin >> a;
        rep(j, a) {
            if (x + 1 < W && ans[y][x + 1] == 0) {
                ans[y][x + 1] = i;
                x++;
            } else if (0 <= x - 1 && ans[y][x - 1] == 0) {
                ans[y][x - 1] = i;
                x--;
            } else {
                ans[y + 1][x] = i;
                y++;
            }
        }
    }
    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j] << " " ;
        }
        cout << endl;
    }

    return 0;
}