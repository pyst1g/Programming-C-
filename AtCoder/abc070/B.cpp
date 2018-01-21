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
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (B < C || D < A) {
        cout << 0 << endl;
        return 0;
    }
    cout << min(B, D) - max(A, C) << endl;

    return 0;
}
