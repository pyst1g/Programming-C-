// finish date: 2018/01/19
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
    int V1, V2, V3, Vm;
    cin >> V1 >> V2 >> V3 >> Vm;
    V1 *= 2;
    V2 *= 2;
    if ((V3 <= Vm && Vm <= V3 * 2) || (Vm <= V3 && V3 <= Vm * 2)) {
        if (Vm * 2 < V2) {
            cout << V1 << endl;
            cout << V2 << endl;
            cout << max(V3, Vm) << endl;
        } else cout << -1 << endl;
    } else cout << -1 << endl;

    return 0;
}
