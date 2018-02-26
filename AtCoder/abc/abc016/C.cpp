// finish date: 2018/01/10
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans *= i;
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> T(N, vector<bool>(N, false));
    vector<vector<bool>> tomotomo(N, vector<bool>(N, false));
    int A, B;
    rep(i, M) {
        cin >> A >> B;
        T[A - 1][B - 1] = T[B - 1][A - 1] = true;
    }
    rep(i, N) {
        rep(j, N) {
            if (T[i][j]) {
                rep(k, N) {
                    if (i != k) tomotomo[k][i] = tomotomo[i][k] = tomotomo[k][i] || (T[j][k] && !T[i][k]);
                }
            }
        }
    }
    vector<int> count(N, 0);
    rep(i, N) {
        rep(j, N) {
            count[i] += tomotomo[i][j];
        }
        cout << count[i] << endl;
    }

    return 0;
}