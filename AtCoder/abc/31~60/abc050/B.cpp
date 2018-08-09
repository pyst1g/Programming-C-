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
    int N, M;
    cin >> N;
    vector<int> T(N);
    rep(i, N) cin >> T[i];
    cin >> M;
    int P, X;
    int total = 0;
    rep(i, N) total += T[i];
    rep(i, M) {
        cin >> P >> X;
        cout << total - T[P - 1] + X << endl;
    }


    return 0;
}