// finish date: 2018/01/23
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
#define vi vector<int>
#define vl vector<ll>
#define bigmod 1000000007
#define INF 500000000


int main() {
    int N;
    cin >> N;
    vl a(N);
    rep(i, N) cin >> a[i];
    FOR(i, 1, N) a[i] += a[i - 1];
    ll mi = LONG_LONG_MAX;
    rep(i,N-1) mi = min(mi,abs(a[N-1]-2*a[i]));
    cout<<mi<<endl;

    return 0;
}

