// finish date: 2018/01/14
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

#define bigmod 1000000007
using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

vector<vector<int>> b, c, field;


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}

int calc(int move) {
    int score;
    if (move == 10) {
        //直接scoreを計算,return
        score = 0;
        rep(i, 2) {
            rep(j, 3) {
                if (field[i][j] == field[i+1][j]) {
                    score += b[i][j];
                }
            }
        }
        rep(i, 3) {
            rep(j, 2) {
                if (field[i][j] == field[i][j+1]) {
                    score += c[i][j];
                }
            }
        }
    } else {
        score = (move & 1) ? INT_MIN : INT_MAX;
        rep(i, 3) {
            rep(j, 3) {
                if (field[i][j]) continue;
                field[i][j] = (move & 1) ? 1 : 2;
                if (move & 1) score = max(score, calc(move + 1));
                else score = min(score, calc(move + 1));
                field[i][j] = 0;
            }
        }
    }
    return score;
}

int main() {
    int sum = 0;
    b = vector<vector<int>>(2, vector<int>(3, 0));
    c = vector<vector<int>>(3, vector<int>(2, 0));
    field = vector<vector<int>>(3, vector<int>(3, 0));

    rep(i, 2) {
        rep(j, 3) {
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    rep(i, 3) {
        rep(j, 2) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }
    int score1 = calc(1);
    int score2 = sum - score1;
    cout << score1 << endl;
    cout << score2 << endl;

    return 0;
}
