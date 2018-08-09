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
    int N;
    string S, now="b";
    cin >> N >> S;
    if(S=="b"){
        cout << 0 << endl;
        return 0;
    }
    FOR(i, 1, S.length()) {
        if (i % 3 == 1) {
            now = "a" + now + "c";
        } else if (i % 3 == 2) {
            now = "c" + now + "a";
        } else {
            now = "b" + now + "b";
        }
        if (S == now) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
