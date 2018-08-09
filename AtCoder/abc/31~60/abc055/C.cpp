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
    ll S, C;
    cin >> S >> C;
    if (S > C/2) {
        cout << C / 2 << endl;
    } else {
        cout << S + (C - S * 2) / 4 << endl;
    }
    return 0;
}
