// finish date: 2018/01/09
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <limits>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    FOR(i, n, INTMAX_MAX) {
        if (i % a == 0 && i % b == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}

