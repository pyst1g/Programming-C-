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
    int N, x;
    cin >> N >> x;
    int left = 0, right;
    ll count = 0;
    rep(i, N) {
        cin >> right;
        if (left + right > x) {
            count += left + right - x;
            left = x - left;
        } else {
            left = right;
        }
    }
    cout << count << endl;
    return 0;
}
