// finish date: 2018/01/08
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
    int n, m;
    cin >> n >> m;
    double posN, posM;
    posN = n % 12 * 5 + (double) m / 12;
    posM = m;
    double ans = min(abs(posN - posM), 60 - abs(posN - posM)) * (360 / 60);
    printf("%.4f\n", ans);
    return 0;
}
