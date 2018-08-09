// finish date: 2018/01/11
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
#define bigmod 1000000007

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (ll)(b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = mul(ans, i);
    }
    return ans;
}

int modpow(int a, int n) {
    if (n == 0) return 1;
    else if (n % 2 == 0) {
        int d = modpow(a, n / 2);
        return mul(d, d);
    } else {
        return mul(a, modpow(a, n - 1));
    }
}

int combination(int n, int k) {
    int val1 = factorial(n);
    int val2 = modpow(factorial(k), bigmod - 2) ;
    int val3 = modpow(factorial(n - k), bigmod - 2);
    return mul(mul(val1, val2), val3);
}

int main() {
    int R, C, X, Y, D, L;
    cin >> R >> C >> X >> Y >> D >> L;
    int ans;
    int a = combination(X * Y, D);
    int b = combination(X * Y - D, L);
    ans = mul(combination(X * Y, D),combination(X * Y - D, L));
    ans = mul(ans,(R - X + 1) * (C - Y + 1));
    cout << ans << endl;

    return 0;
}