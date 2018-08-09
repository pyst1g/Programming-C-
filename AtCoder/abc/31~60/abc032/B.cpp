// finish date: 2018/01/09
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

int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans *= i;
    }
    return ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    if (s.length() < k) cout << 0 << endl;
    else {
        map<string, int> mp;
        rep(i, s.length()) {
            if (i + k <= s.length()) {
                mp[s.substr(i, k)] = 0;
            }
        }

        cout << mp.size() << endl;
    }

    return 0;
}

