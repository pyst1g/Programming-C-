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
    int sum = 0;
    int nuke;
    FOR(i, 1, 10) {
        FOR(j, 1, 10) {
            sum += i * j;
        }
    }
    nuke = sum - N;
    FOR(i, 1, 10) {
        FOR(j, 1, 10) {
            if (i * j == nuke) {
                cout << i << " x " << j << endl;
            }
        }
    }

    return 0;
}



