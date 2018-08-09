// finish date: 2018/01/11
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

#define bigmod 1000000007
using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}

int main() {
    int W, a, b;
    cin >> W >> a >> b;
    int ans = 0;
    bool con1, con2, con3;
    con1 = a <= b && b <= a + W;
    con2 = a <= b + W && b + W <= a + W;
    con3 = b <= a && a <= b + W;
    if (con1 || con2 || con3) ans = 0;
    else ans = abs(a - b) - W;
    cout << ans << endl;
    return 0;
}
