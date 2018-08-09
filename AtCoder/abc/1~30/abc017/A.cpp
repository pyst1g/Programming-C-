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
    int s1, e1;
    int s2, e2;
    int s3, e3;
    cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;
    cout << s1 * e1 / 10 + s2 * e2 / 10 + s3 * e3 / 10 << endl;
}
