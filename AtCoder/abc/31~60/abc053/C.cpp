// finish date: 2018/01/21
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    ll x;
    cin >> x;
    ll loop = x / 11;
    x -= loop * 11;
    ll ans = loop * 2;
    if (x != 0) {
        if (x <= 6) ans += 1;
        else ans += 2;
    }
    cout << ans << endl;

    return 0;
}
