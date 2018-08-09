// finish date: 2018/01/10
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

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
    string w;
    cin >> w;
    map<char, int> mp;
    rep(i, w.length()) mp[w[i]]++;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}