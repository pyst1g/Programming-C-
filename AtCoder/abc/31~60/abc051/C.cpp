// finish date: 2018/01/15
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 1000000000

vector<vector<int>> b, c, field;


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}


int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string str = "";
    rep(i, tx - sx) str += "R";
    rep(i, ty - sy) str += "U";
    rep(i, tx - sx) str += "L";
    rep(i, ty - sy) str += "D";

    str += "D";
    rep(i, tx - sx + 1) str += "R";
    rep(i, ty - sy + 1) str += "U";
    str += "LU";
    rep(i, tx - sx + 1) str += "L";
    rep(i, ty - sy+1) str += "D";
    str += "R";

    cout << str << endl;
}
