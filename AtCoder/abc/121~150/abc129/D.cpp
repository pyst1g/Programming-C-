// finish date: 2019/06/09

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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
    int H, W;
    cin >> H >> W;
    vs S(H + 2);
    FOR(i, 1, H + 1) {
        cin >> S[i];
        S[i] = "#" + S[i] + "#";
    }
    S[0] = "";
    S[H + 1] = "";
    rep(i, W + 2) {
        S[0] += "#";
        S[H + 1] += "#";
    }


    vvi left(H + 2, vi(W + 2, 0));
    vvi right(H + 2, vi(W + 2, 0));
    vvi up(H + 2, vi(W + 2, 0));
    vvi down(H + 2, vi(W + 2, 0));

    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            if (S[i][j] == '#') continue;
            if (S[i][j - 1] == '.') left[i][j] += left[i][j - 1] + 1;
        }
    }

    FOR(i, 1, H + 1) {
        for (int j = W; j >= 1; j--) {
            if (S[i][j] == '#') continue;
            if (S[i][j + 1] == '.') right[i][j] += right[i][j + 1] + 1;
        }
    }


    FOR(j, 1, W + 1) {
        FOR(i, 1, H + 1) {
            if (S[i][j] == '#') continue;
            if (S[i - 1][j] == '.') up[i][j] += up[i - 1][j] + 1;
        }
    }

    FOR(j, 1, W + 1) {
        for (int i = H; i >= 1; i--) {
            if (S[i][j] == '#') continue;
            if (S[i + 1][j] == '.') down[i][j] += down[i + 1][j] + 1;
        }
    }

    int ma = 0;

    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            ma = max(ma, 1 + left[i][j] + right[i][j] + up[i][j] + down[i][j]);
        }
    }
    cout << ma<< endl;

    return 0;
}
