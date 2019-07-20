// finish date: 2018/02/24

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

int N, M, A, B;
vvc ans;

void calc(int y1, int x1, int y2, int x2) {
    for (int i = y1; i < y2; i += 2) {
        for (int j = x1; j < x2; j += 2) {
            if (A > 0) {
                ans[i][j] = '<';
                ans[i][j + 1] = '>';
                A--;
                if (A > 0) {
                    ans[i + 1][j] = '<';
                    ans[i + 1][j + 1] = '>';
                    A--;
                }
            } else if (B > 0) {
                ans[i][j] = '^';
                ans[i + 1][j] = 'v';
                B--;
                if (B > 0) {
                    ans[i][j + 1] = '^';
                    ans[i + 1][j + 1] = 'v';
                    B--;
                }
            } else break;
        }
    }

}


int main() {
    cin >> N >> M >> A >> B;
    if (N * M < 2 * A + 2 * B) {
        cout << "NO" << endl;
        return 0;
    }
    ans = vvc(N, vc(M, '.'));
    if (N % 2 == 0 && M % 2 == 0) {
        calc(0, 0, N, M);
    } else if (N % 2 == 0 && M % 2 == 1) {
        for (int i = 0; i < N - 1; i += 2) {
            if (B == 0) break;
            ans[i][0] = '^';
            ans[i + 1][0] = 'v';
            B--;
        }
        calc(0, 1, N, M);
    } else if (N % 2 == 1 && M % 2 == 0) {
        for (int i = 0; i < M - 1; i += 2) {
            if (A == 0) break;
            ans[0][i] = '<';
            ans[0][i + 1] = '>';
            A--;
        }
        calc(1, 0, N, M);
    } else {
        for (int i = 0; i < N - 1; i += 2) {
            if (B == 0) break;
            ans[i][0] = '^';
            ans[i + 1][0] = 'v';
            B--;
            if (i == 0) i++;
        }
        for (int i = 1; i < M - 1; i += 2) {
            if (A == 0) break;
            ans[0][i] = '<';
            ans[0][i + 1] = '>';
            A--;
        }
        if (N == 1 || M == 1) {
            if (A == 0 && B == 0) {
                cout << "YES" << endl;
                rep(i, N) {
                    rep(j, M) {
                        cout << ans[i][j];
                    }
                    cout << endl;
                }
            } else cout << "NO" << endl;
            return 0;
        }
        if (A % 2 == 1 ) {
            if (B > 0) {
                ans[1][2] = '^';
                ans[2][2] = 'v';
                B--;
            }
            if (A > 0) {
                ans[2][0] = '<';
                ans[2][1] = '>';
                A--;
            }

            calc(1, 3, 3, M);
            calc(3, 1, N, M);
        } else {
            calc(1, 1, N, M);
        }
    }


    if (A == 0 && B == 0) {
        cout << "YES" << endl;
        rep(i, N) {
            rep(j, M) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}



