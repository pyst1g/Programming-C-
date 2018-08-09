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
    int N, A, B;
    cin >> N >> A >> B;
    int pos = 0;
    string s;
    int d;
    rep(i, N) {
        cin >> s >> d;
        d = min(B, max(A, d)); // 実際移動する距離
        if (s == "West") {
            pos -= d;
        } else {
            pos += d;
        }
    }
    if (pos == 0) cout << 0 << endl;
    else if (pos > 0) cout << "East " << pos << endl;
    else cout << "West " << -pos << endl;


    return 0;
}
