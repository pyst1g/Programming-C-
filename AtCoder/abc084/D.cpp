// finish date: 2018/01/02
#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

int main() {
    int maxN = 100001;
    int Q, l, r;
    int Prime[maxN];
    rep(i, maxN) Prime[i] = 1;
    Prime[0] = Prime[1] = 0;
    int x;
    rep(i, sqrt(maxN - 1) + 1) {
        x = i * 2;
        if (!Prime[i]) continue;
        while (x < maxN) {
            Prime[x] = 0;
            x += i;
        }
    }
    for (int i = maxN - 1; i >= 0; i--) if (!Prime[(i + 1) / 2]) Prime[i] = 0;
    rep(i, maxN - 1) {
        Prime[i + 1] += Prime[i];
    }
    cin >> Q;
    int ans;
    rep(i, Q) {
        cin >> l >> r;
        ans = Prime[r] - Prime[l - 1];
        cout << ans << endl;
    }
    return 0;
}