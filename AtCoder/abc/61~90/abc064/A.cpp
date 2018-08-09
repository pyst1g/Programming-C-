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
    int r, g, b;
    cin >> r >> g >> b;
    if ((100 * r + 10 * g + b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
