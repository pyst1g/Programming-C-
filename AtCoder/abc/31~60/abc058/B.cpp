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
    string O, E;
    cin >> O >> E;
    string ans = "";
    rep(i, E.length()) {
        ans += O[i];
        ans += E[i];
    }
    if (O.length() > E.length()) ans += O[O.length() - 1];
    cout << ans << endl;


    return 0;
}
