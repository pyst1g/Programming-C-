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
    int N, R;
    cin >> N;
    int r2 = 0;
    int sign = 1;
    vector<int> v(1001, 0);
    rep(i, N) {
        cin >> R;
        v[R] = (v[R] + 1) % 2; //奇偶の判別のみが必要なので
    }
    for (int i = 1000; i >= 1; i--) {
        if (v[i] == 1) {
            r2 += i * i * sign;
            sign *= -1; //符号の反転
        }
    }
    printf("%.6f\n", r2 * M_PI);

    return 0;
}
