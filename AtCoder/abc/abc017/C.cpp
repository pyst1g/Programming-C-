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
    vector<int> imos(M + 2, 0);
    int l, r, s;
    int sum = 0;
    rep(i, N) {
        cin >> l >> r >> s;
        imos[l] += s;
        imos[r + 1] -= s;
        sum += s;

    }
    int mi = INT_MAX;
    FOR(i, 1, M + 1) {
        imos[i] += imos[i - 1];
        mi = min(mi, imos[i]);
    }

    cout << sum - mi << endl;
    return 0;
}