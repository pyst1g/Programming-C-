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
    string X;
    string str = "oku";
    cin >> X;
    rep(i, X.length()) {
        if (!isExist(X[i], str)) {
            if (i != X.length() - 1) {
                if (X[i] == 'c' && X[i+1] == 'h') {
                    i++;
                    continue;
                }
            }
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;


    return 0;
}
