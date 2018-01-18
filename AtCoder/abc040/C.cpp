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
    int N;
    cin >> N;
    vector<int> a(N), cost(N, INT_MAX);
    rep(i, N) cin >> a[i];
    cost[0] = 0;
    cost[1] = abs(a[1] - a[0]);
    FOR(i, 2, N) {
        cost[i] = min(cost[i - 2] + abs(a[i] - a[i - 2]), cost[i - 1] + abs(a[i] - a[i - 1]));
    }
    cout << cost[N - 1] << endl;
    return 0;
}
