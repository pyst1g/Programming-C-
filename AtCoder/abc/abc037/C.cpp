// finish date: 2018/01/17
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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    ll sum = 0;
    int count = 1;
    rep(i, N / 2) {
        sum += (ll) a[i] * min(count, min(N-K+1,K));
        sum += (ll) a[N - 1 - i] * min(count, min(N-K+1,K));
        count++;
    }
    if (N % 2 == 1) sum += (ll) a[N / 2] * min(count, min(N-K+1,K));

    cout << sum << endl;
    return 0;
}
