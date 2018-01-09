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
    int N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;
    int c = 0;
    double doubleC = 0;
    ll mi = LONG_LONG_MAX;
    rep(a, N + 1) {
        if (doubleC < 0) break;
        doubleC = (double) ((ll) E * N - H - (ll)(E + B) * a) / (E + D);
        c = (int) floor(doubleC) + 1;
        if (doubleC < 0) c = 0;
        if (c <= N - a) mi = ((ll) a * A + (ll)c * C < mi) ? (ll)a * A + (ll)c * C : mi;
    }
    cout << mi << endl;

    return 0;
}



