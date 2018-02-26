// finish date: 2018/01/21
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    rep(i, H) rep(j, W) if (S[i][j] == '.') S[i][j] = '0';
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                if (i > 0 && j > 0 && S[i - 1][j - 1] != '#') S[i - 1][j - 1]++;
                if (i > 0 && S[i - 1][j] != '#') S[i - 1][j]++;
                if (i > 0 && j < W - 1 && S[i - 1][j + 1] != '#') S[i - 1][j + 1]++;

                if (j > 0 && S[i][j - 1] != '#') S[i][j - 1]++;
                if (j < W - 1 && S[i][j + 1] != '#') S[i][j + 1]++;

                if (i < H - 1 && j > 0 && S[i + 1][j - 1] != '#') S[i + 1][j - 1]++;
                if (i < H - 1 && S[i + 1][j] != '#') S[i + 1][j]++;
                if (i < H - 1 && j < W - 1 && S[i + 1][j + 1] != '#') S[i + 1][j + 1]++;
            }
        }
    }
    rep(i, H) cout << S[i] << endl;

    return 0;
}
