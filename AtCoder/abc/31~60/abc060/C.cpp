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


int main() {
    int N, T;
    cin >> N >> T;
    int t1, t2;
    cin >> t1;
    int sum = 0;
    rep(i, N - 1) {
        cin >> t2;
        sum += min(T, t2 - t1);
        t1 = t2;
    }
    sum += T;
    cout << sum << endl;

    return 0;
}

