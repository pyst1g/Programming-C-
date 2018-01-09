// finish date: 2018/01/09
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

bool dfs(vector<vector<int>> T, int N, int K, int depth, int val) {
    if (depth == N) return val == 0;
    rep(i, K) {
        if (dfs(T, N, K, depth + 1, val ^ T[depth][i])) return true;
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> T(N, vector<int>(K));
    rep(i, N) rep(j, K) cin >> T[i][j];
    if (dfs(T, N, K, 0, 0)) cout << "Found" << endl;
    else cout << "Nothing" << endl;

    return 0;
}



