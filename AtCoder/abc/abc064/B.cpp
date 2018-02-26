// finish date: 2018/01/21
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
    int mi = INF, ma = -INF;
    int a;
    rep(i, N) {
        cin >> a;
        mi = min(mi, a);
        ma = max(ma, a);
    }
    cout << ma - mi << endl;

    return 0;
}
