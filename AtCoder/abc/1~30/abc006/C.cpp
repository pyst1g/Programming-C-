// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>

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
    int N, M;
    cin >> N >> M;
    int calval = M - 2 * N;
    int a, b, c;
    c = calval / 2;
    b = calval % 2;
    a = N - b - c;
    if (b + c > N || a < 0 || b < 0 || c < 0) cout << "-1 -1 -1" << endl;
    else cout << a << " " << b << " " << c << endl;
}
