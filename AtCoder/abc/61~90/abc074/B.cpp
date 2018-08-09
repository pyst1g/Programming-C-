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
    int N, K;
    cin >> N >> K;
    int sum = 0;
    int x;
    rep(i, N) {
        cin >> x;
        sum += min(K - x, x) * 2;
    }
    cout << sum << endl;

    return 0;
}
