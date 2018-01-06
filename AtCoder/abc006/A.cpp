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
    int N;
    cin >> N;
    if(N==3 || N%3 == 0) cout << "YES" << endl;
    else cout <<"NO" << endl;
    return 0;
}
