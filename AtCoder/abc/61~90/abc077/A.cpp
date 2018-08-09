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
    string C1, C2;
    cin >> C1 >> C2;
    string C3 = C1, C4 = C2;
    reverse(C3.begin(), C3.end());
    reverse(C4.begin(), C4.end());
    if (C2 == C3 && C1 == C4) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
