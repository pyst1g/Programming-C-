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
    int N;
    string str;
    cin >> N;
    map<string, int> m;
    rep(i, N) {
        cin >> str;
        m[str] = (m.find(str) != m.end()) ? m[str] + 1 : 1;
    }
    string str_max;
    int val_max = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second > val_max) {
            str_max = itr->first;
            val_max = itr->second;
        }
    }
    cout << str_max << endl;
    return 0;
}
