// finish date: 2018/01/23
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
#define vi vector<int>
#define vl vector<ll>
#define bigmod 1000000007
#define INF 500000000


int main() {
    int N;
    cin >> N;
    vi a(100001, 0);
    int in;
    rep(i, N) {
        cin >> in;
        a[in]++;
    }
    int ma = -INF;
    FOR(i, 2, 100001) ma = max(ma, a[i - 2] + a[i - 1] + a[i]);
    cout << ma << endl;

    return 0;
}

