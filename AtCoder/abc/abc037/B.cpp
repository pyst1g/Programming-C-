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
    int N, Q, L, R, T;
    cin >> N >> Q;
    vector<int> a(N, 0);
    rep(i, Q) {
        cin >> L >> R >> T;
        FOR(j, L - 1, R) {
            a[j] = T;
        }
    }
    rep(i, N) cout << a[i] << endl;
}



