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
    int N, S, T, W;
    int val = 0;
    int A;
    cin >> N >> S >> T >> W;
    if (S <= W && W <= T) {
        val++;
    }
    rep(i, N - 1) {
        cin >> A;
        W += A;
        if (S <= W && W <= T) val++;
    }
    cout << val << endl;

    return 0;
}
