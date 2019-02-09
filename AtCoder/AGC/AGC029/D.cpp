// finish date: 2018/12/21

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
typedef vector<vector<vector<double>>> vvvd;
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
    //入力と変数宣言
    int H, W, N;
    cin >> H >> W >> N;
    vi X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }
    set<pii> block;
    rep(i, N) block.insert(pii(X[i], Y[i]));
    //rep(i, H) block.insert(pii(i, W));
    rep(i, W) block.insert(pii(H, i));
    vi move(W, INT_MAX);
    move[0] = 0;

    int x = 0, y = 0;
    while (x < H && y < W) {
        if (block.find(pii(x + 1, y)) == block.end()) {
            x += 1;
            move[y] = x;
            if (block.find(pii(x, y + 1)) == block.end()) {
                y += 1;
            }
        } else {
            move[y] = x;
            break;
        }
    }

    int ans = INT_MAX;
    for (auto b:block) {
        if (move[b.second] < b.first) {
            ans = min(ans, b.first);
        }
    }
    cout << ans << endl;

    return 0;
}

