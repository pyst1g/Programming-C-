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
    int N, a, b, K;
    cin >> N >> a >> b >> K;
    vector<int> P(K);
    rep(i, K) cin >> P[i];
    vector<int> t(N + 1, 0);
    t[a]++;
    t[b]++;
    rep(i, K) {
        if (t[P[i]] >= 1) {
            cout << "NO" << endl;
            return 0;
        }
        t[P[i]]++;
    }
    cout << "YES" << endl;
    return 0;
}
