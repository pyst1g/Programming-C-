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
    string s;
    cin >> s;
    char beforeChar = s[0];
    string ans = "";
    int count = 1;
    if (s.length() == 1) cout << s[0] << 1 << endl;
    else {
        FOR(i, 1, s.length()) {
            if (s[i] == beforeChar) count++;
            else {
                ans += beforeChar;
                ans += to_string(count);
                count = 1;
                beforeChar = s[i];
            }
            if (i == s.length() - 1) {
                ans += beforeChar;
                ans += to_string(count);
            }
        }
        cout << ans << endl;
    }



    return 0;
}
