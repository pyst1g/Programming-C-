// finish date: 2018/01/06
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
    int N, Y;
    cin >> N >> Y;
    int a=-1, b=-1, c=-1;
    Y /= 1000;
    rep(i, N+1) {
        if ((Y - N - 4 * i) % 9 == 0) {
            b = i;
            a = (Y - N - 4 * b) / 9;
            c = N - a - b;
            if (a >= 0 && b >= 0 && c >= 0) break;
        }
    }
    if (a < 0 || b < 0 || c < 0) cout << "-1 -1 -1" << endl;
    else cout << a << " " << b << " " << c << endl;
}
