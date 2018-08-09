// finish date: 2018/01/09
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
    string S;
    int T;
    cin >> S >> T;
    int x = 0, y = 0;
    int hatena = 0;
    rep(i, S.length()) {
        switch (S[i]) {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            default:
                hatena++;
                break;
        }

    }
    if (T == 1) {
        cout << abs(x) + abs(y) + hatena << endl;
    } else {
        if (abs(x) + abs(y) < hatena) {
            if ((abs(x) + abs(y) - hatena) % 2) cout << 1 << endl;
            else cout << 0 << endl;
        } else {
            cout << abs(x) + abs(y) - hatena << endl;
        }
    }
    return 0;
}

