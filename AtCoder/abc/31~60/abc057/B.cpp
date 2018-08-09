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
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N), c(M), d(M);
    rep(i, N) cin >> a[i] >> b[i];
    rep(i, M) cin >> c[i] >> d[i];

    int points;
    int maxDis;
    int distance;
    rep(i, N) {
        points = 0;
        maxDis = INT_MAX;
        rep(j, M) {
            distance = abs(c[j] - a[i]) + abs(d[j] - b[i]);
            if (distance < maxDis) {
                points = j;
                maxDis = distance;
            }
        }
        cout << points + 1 << endl;
    }

    return 0;
}
