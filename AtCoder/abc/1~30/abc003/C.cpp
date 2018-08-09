// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>

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
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    rep(i, N) cin >> R[i];
    sort(R.begin(), R.end());
    double ans = 0;
    rep(i, K) {
        ans += R[N - i - 1] / pow(2.0, i + 1);
    }
    printf("%.6f\n",ans);
    return 0;
}
