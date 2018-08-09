// finish date: 2018/01/20
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


int main() {
    int N, T, A;
    cin >> N;
    ll X = 1, Y = 1;
    ll n;
    rep(i, N) {
        cin >> T >> A;
        n = max((X+T-1)/T,(Y+A-1)/A);
        X = n*T;
        Y = n*A;
    }
    cout << X + Y << endl;
    return 0;
}
