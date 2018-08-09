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
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) {
        cin >> s[i];
    }

    rep(i, N) {
        for (int j = N - 1; j >= 0; j--) {
            cout << s[j][i];
        }
        cout << endl;
    }
}



