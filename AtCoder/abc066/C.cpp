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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    int pos = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        b[pos] = a[i];
        pos++;
    }
    int s = (n % 2 == 0) ? 0 : 1;
    for (int i = s; i < n; i += 2) {
        b[pos] = a[i];
        pos++;
    }
    rep(i, n) cout << b[i] << " ";
    cout << endl;

    return 0;
}

