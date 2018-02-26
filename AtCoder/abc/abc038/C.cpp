// finish date: 2018/01/18
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
    int N, a;
    cin >> N;
    ll ans = 0;
    int prev = 0;
    int count = 0;
    rep(i, N) {
        cin >> a;
        if (prev >= a) {
            if (count != 1) ans += (ll)count * (count - 1) / 2;
            prev = a;
            count = 1;
        } else {
            prev = a;
            count++;
        }
        if (i == N - 1 && count != 1) ans += (ll)count * (count - 1) / 2;
    }
    ans += N;
    cout << ans << endl;
}
