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
    string s;
    cin >> s;
    vector<int> a(6, 0);
    rep(i, s.length()) a[s[i] - 'A']++;
    rep(i, 6) {
        if (i != 5) cout << a[i] << " ";
        else cout << a[i];
    }
    cout << endl;
    return 0;
}