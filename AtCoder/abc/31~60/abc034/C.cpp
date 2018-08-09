// finish date: 2018/01/27
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
#define vb vector<bool>5
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 1050000000

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int gyakugen(int a, int p, int b = -1) {
    if (b < 0) b = p - 2;  //int gyakugen(int a, int p, int b = p - 2とできなかったため。)
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        int d = gyakugen(a, p, b / 2);
        return mul(d, d);
    } else {
        return mul(a, gyakugen(a, p, b - 1));
    }
}

int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) ans = mul(ans, i);
    return ans;
}

int main() {
    int W, H;
    cin >> W >> H;
    W--;
    H--;
    cout << mul(fact(W + H), mul(gyakugen(fact(W), bigmod), gyakugen(fact(H), bigmod))) << endl;

    return 0;
}

