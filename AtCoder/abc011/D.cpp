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


int main() {
    int N, D, X, Y;
    cin >> N >> D >> X >> Y;
    if (!(X % D == 0 && Y % D == 0)) {
        cout << 0 << endl;
        return 0;
    }
    X /= D;
    Y /= D;
    X = abs(X);
    Y = abs(Y);
    vvd nCk_div4(N + 1, vd(N + 1, 0));
    nCk_div4[0][0] = 1;
    FOR(i, 1, N + 1) {
        rep(j, i + 1) {
//            if (j == 0) {
//                nCk_div4[i][j] = i;
//                continue;
//            }
            if (0 < j) nCk_div4[i][j] += nCk_div4[i - 1][j - 1] / 4.0;
            if (j < i) nCk_div4[i][j] += nCk_div4[i - 1][j];
        }
    }
    double ans = 0;
    //i:y方向に移動する回数
    rep(i, N + 1) {
        if (i < Y || (i - Y) % 2 == 1) continue;
        if (N - i < X || (N - i - X) % 2 == 1) continue;
        int Yplus = (i - Y) / 2 + Y;
        int Yminus = (i - Y) / 2;
        int Xplus = (N - i - X) / 2 + X;
        int Xminus = (N - i - X) / 2;
        ans += nCk_div4[N][Yplus] * nCk_div4[N - Yplus][Yminus]
               * nCk_div4[N - Yplus - Yminus][Xplus] * nCk_div4[Xminus][Xminus];
    }


    printf("%.9f\n", ans);
    return 0;
}



