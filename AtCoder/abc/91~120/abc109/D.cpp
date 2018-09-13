// finish date: 2018/09/13
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>>
        vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>>
        vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    int H, W;
    cin >> H >> W;
    vvi a(H, vi(W));
    int N = 0;
    rep(i, H) {
        rep(j, W) {
            cin >> a[i][j];
        }
    }
    vi y1, x1, y2, x2;
    int x, y;
    int dir;
    rep(y, H) {
        rep(j, W) {
            if (y == H - 1 && j == W - 1) break;
            if (y % 2 == 0) x = j, dir = 1;
            else x = W - 1 - j, dir = -1;
            if (a[y][x] != 0 && a[y][x] % 2 == 1) {
                N++;
                if (j == W - 1) {
                    a[y + 1][x] += 1;
                    a[y][x] -= 1;
                    y1.emplace_back(y);
                    x1.emplace_back(x);
                    y2.emplace_back(y + 1);
                    x2.emplace_back(x);
                } else {
                    a[y][x + dir] += 1;
                    a[y][x] -= 1;
                    y1.emplace_back(y);
                    x1.emplace_back(x);
                    y2.emplace_back(y);
                    x2.emplace_back(x + dir);
                }
            }
        }
    }
    cout << N << endl;
    rep(i, N) {
        cout << y1[i]+1 << " " << x1[i]+1 << " " << y2[i]+1 << " " << x2[i]+1 << endl;
    }

    return 0;
}

