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
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2) cout << l3 << endl;
    else if (l2 == l3) cout << l1 << endl;
    else if (l3 == l1) cout << l2 << endl;

    return 0;
}
