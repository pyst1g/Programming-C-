// finish date: 2018/01/31
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

//足し算
int add(int a, int b) {
    return (a + b) % bigmod;
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    int n, m;
    cin >> n >> m;
    vi x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int X = 0, Y = 0;
    rep(i, n - 1) {
        X = add(X, mul(x[i + 1] - x[i], mul(n - 1 - i, mul(m, (m - 1)) / 2)));
    }
    rep(i, m - 1) {
        Y = add(Y, mul(y[i + 1] - y[i], mul(m - 1 - i, mul(n, (n - 1)) / 2)));
    }
    cout << mul(X, Y) << endl;


    return 0;
}

