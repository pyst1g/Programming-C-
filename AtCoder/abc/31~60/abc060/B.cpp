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
    int A, B, C;
    cin >> A >> B >> C;
    FOR(i,1,B+1) {
        if ((A*i) % B == C) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
