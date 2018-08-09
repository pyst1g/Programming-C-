// finish date: 2018/01/27
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 1050000000

//pattern=1は正負正負,-1は負正負正
ll calc(vl a, int pattern) {
    ll count = 0;
    ll sa;
    ll bi = 0;
    rep(i, a.size()) {
        if ((pattern == 1 && a[i] + bi > 0) || (pattern == -1 && a[i] + bi < 0)) {
            pattern *= -1;
            continue;
        }
        sa = a[i] + bi - pattern;
        bi -= sa;
        count += llabs(sa);
        pattern *= -1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    FOR(i, 1, n) a[i] += a[i - 1];
    ll mi = min(calc(a, 1), calc(a, -1));
    cout << mi << endl;
    return 0;
}

