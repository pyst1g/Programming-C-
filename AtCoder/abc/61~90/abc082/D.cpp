// finish date: 2018/12/15

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
    string s;
    int x, y;
    cin >> s >> x >> y;
    int N = s.length();
    int st = N;
    //最初のFの処理

    rep(i, N) {
        if (s[i] == 'F') x--;
        else {
            st = i + 1;
            break;
        }
    }
    vi X, Y;
    int sign = 1;
    int cnt = 0;

    //XとYの移動距離をリストに
    FOR(i, st, N) {
        if (s[i] == 'F') cnt++;
        if (i == N - 1 || s[i] == 'T') {
            if (sign == 1) Y.push_back(cnt);
            else X.push_back(cnt);
            sign *= -1;
            cnt = 0;
        }
    }

    vvb isReachedX(X.size() + 1, vb(16001, false)), isReachedY(Y.size() + 1, vb(16001, false));
    isReachedX[0][8000] = true;
    isReachedY[0][8000] = true;
    FOR(i, 1, isReachedX.size()) {
        rep(j, isReachedX[0].size()) {
            if (isReachedX[i - 1][j] == true) {
                isReachedX[i][j + X[i - 1]] = true;
                isReachedX[i][j - X[i - 1]] = true;
            }
        }
    }

    FOR(i, 1, isReachedY.size()) {
        rep(j, isReachedY[0].size()) {
            if (isReachedY[i - 1][j] == true) {
                isReachedY[i][j + Y[i - 1]] = true;
                isReachedY[i][j - Y[i - 1]] = true;
            }
        }
    }


    if (x + 8000>=0 && y+8000>=0 &&isReachedX[isReachedX.size() - 1][x + 8000] && isReachedY[isReachedY.size() - 1][y + 8000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

