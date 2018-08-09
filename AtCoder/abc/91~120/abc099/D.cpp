// finish date: 2018/06/10
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    int N, C;
    cin >> N >> C;
    vvi D(C, vi(C));
    vvi c(N, vi(N));
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, C) rep(j, C) cin >> D[i][j];
    rep(i, N) {
        rep(j, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<pii>> amari(3, vector<pii >(C, pii(0, 0)));
    rep(k, C) {
        rep(i, N) {
            rep(j, N) {
                amari[(i + j) % 3][k] = pii(amari[(i + j) % 3][k].first + D[c[i][j]][k], k);
            }
        }
    }
    sort(amari[0].begin(), amari[0].end());
    sort(amari[1].begin(), amari[1].end());
    sort(amari[2].begin(), amari[2].end());
    int mi = INF;
    rep(i, 3) {
        rep(j, 3) {
            rep(k, 3) {
                if (amari[0][i].second != amari[1][j].second &&
                    amari[1][j].second != amari[2][k].second &&
                    amari[2][k].second != amari[0][i].second) {
                    mi = min(mi, amari[0][i].first + amari[1][j].first + amari[2][k].first);
                }
            }
        }
    }
    cout << mi << endl;

    return 0;
}




