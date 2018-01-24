// finish date: 2018/01/22
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
    int N, M;
    cin >> N >> M;
    if (abs(N - M) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    int n=N,m=M;
    while (n != 0) {
        ans = mul(ans, n);
        n--;
    }
    while (m != 0) {
        ans = mul(ans, m);
        m--;
    }
    if (N == M) cout << mul(2, ans) << endl;
    else cout << ans << endl;

    return 0;
}

