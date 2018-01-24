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
    int bx = 0, by = 0;
    int t, x, y;
    int d;
    rep(i, N) {
        cin >> t >> x >> y;
        d = abs(bx - x) + abs(by - y);
        if (d > t) {
            cout << "No" << endl;
            return 0;
        }
        if ((t % 2 == 0 && d % 2 == 1) || (t % 2 == 1 && d % 2 == 0)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}
