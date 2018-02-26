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
    ll a, b, x;
    cin >> a >> b >> x;
    if (a == 0) {
        if (b == 0) cout << 1 << endl;
        else cout << b / x + 1 << endl;
    } else cout << b / x - ((a - 1 > 0) ? a - 1 : 0) / x;

    return 0;
}