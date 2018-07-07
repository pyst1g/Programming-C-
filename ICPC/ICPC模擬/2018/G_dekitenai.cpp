// finish date: 2018/07/03
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<long double> vd;
typedef vector<vector<long double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    while (true) {
        int N;
        ll M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        int L = 6 * N + 1;
        vvd prob(40, vd(L, 0)); //prob[試行回数bit][前合計][後合計]
        vd E(40, 0);
        prob[0][1] = prob[0][2] = prob[0][3] = prob[0][4] = prob[0][5] = prob[0][6] = 1.0 / 6.0;
        FOR(k, 1, N) {
            for (int i = L - 1; i > 0; i--) {
                if (prob[0][i] == 0) continue;
                FOR(j, 1, 7) {
                    prob[0][i + j] += prob[0][i] / 6.0;
                }
                prob[0][i] = 0;
            }
        }
        rep(i, L) {
            E[0] += prob[0][i] * i;
        }

        FOR(k, 1, 40) {
            rep(i, L) {
                prob[k][i] += prob[k - 1][i];
                if (i < E[k - 1]) {
                    rep(j, L) {
                        prob[k][j] += prob[k - 1][i] * prob[k - 1][j];
                        prob[k][i] -= prob[k - 1][i] * prob[k - 1][j];
                    }
                }
            }
            rep(i, L) {
                E[k] += prob[k][i] * i;
            }
        }
        vd probM(L, 0);
        probM[0] = 1;
        vd probM2;


        rep(k, 40) {
            if (M & (1LL << k)) {
                probM2 = vd(L, 0);
                rep(i, L) {
                    if (probM[i] == 0) continue;
                    probM2[i] += probM[i];
                    if (i < E[k]) {
                        rep(j, L) {
                            probM2[j] += probM[i] * prob[k][j];
                            probM2[i] -= probM[i] * prob[k][j];
                        }
                    }
                }
                probM = probM2;
            }
        }
        double ans = 0;
        rep(i, L) {
            ans += probM[i] * i;
        }
        cout << ans << endl;
    }

    return 0;
}
