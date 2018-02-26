// finish date: 2018/01/23
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define bigmod 1000000007
#define INF 500000000


int main() {
    int N, Q, P;
    cin >> N;
    vi ma(N * N + 1);
    vvi D(N, vi(N));
    rep(i, N) rep(j, N) cin >> D[i][j];
    rep(i, N) {
        rep(j, N) {
            if (i > 0) D[i][j] += D[i - 1][j];
            if (j > 0) D[i][j] += D[i][j - 1];
            if (i > 0 && j > 0) D[i][j] -= D[i - 1][j - 1];
        }
    }
    int sum;
    rep(y1, N) {
        FOR(y2, y1, N) {
            rep(x1, N) {
                FOR(x2, x1, N) {
                    sum = D[y2][x2];
                    if (y1 > 0) sum -= D[y1 - 1][x2];
                    if (x1 > 0) sum -= D[y2][x1 - 1];
                    if (y1 > 0 && x1 > 0) sum += D[y1 - 1][x1 - 1];
                    ma[(y2 - y1 + 1) * (x2 - x1 + 1)] = max(ma[(y2 - y1 + 1) * (x2 - x1 + 1)], sum);
                }
            }
        }
    }
    FOR(i, 1, ma.size()) ma[i] = max(ma[i], ma[i - 1]);
    cin >> Q;
    rep(i, Q) {
        cin >> P;
        cout << ma[P] << endl;
    }

    return 0;
}

