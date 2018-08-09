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
    int X;
    cin >> X;
    int b2_4ac = (int) sqrt(1 + (ll) 8 * X);
    int n = (-1 + b2_4ac) / 2;
    if ((ll) b2_4ac * b2_4ac != 1 + (ll) 8 * X) n++;
    cout << n << endl;

    return 0;
}
