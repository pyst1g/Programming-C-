// finish date: 2018/06/17
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int,int>
const int bigmod = 998244353;
#define INF 1050000000

//足し算
int add(int a, int b) {
    return (a + b) % bigmod;
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int N;
vi fact;

//割り算  -  逆元(求めたい数とbigmodを渡す)
int divine(int a, int p = bigmod, int b = -1) {
    if (b < 0) b = p - 2;  //int gyakugen(int a, int p, int b = p - 2とできなかったため。)
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        int d = divine(a, p, b / 2);
        return mul(d, d);
    } else {
        return mul(a, divine(a, p, b - 1));
    }
}

//nやkが大きな場合nCkをO(1)で求めるようにプログラムを適切に変更する。
int nCk_gyakugen(int n, int k, int p = bigmod) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    if (n < k) return 0;
    int denominator = fact[n];
    int molecule1 = fact[k];
    int molecule2 = fact[n - k];
    return mul(denominator, mul(divine(molecule1), divine(molecule2)));
}

int main() {
    int N, A, B;
    ll K;
    cin >> N >> A >> B >> K;
    int ans = 0;

    fact = vi(N + 1, 0);
    fact[0] = 1;
    FOR(i, 1, N + 1) {
        fact[i] = mul(i, fact[i - 1]);
    }

    rep(n, N + 1) {
        ll res = K - (ll) A * n;
        if (res % B != 0) continue;
        ll m = res / B;
        if (!(0 <= m && m <= N)) continue;
        ans = add(ans, mul(nCk_gyakugen(N, n, bigmod), nCk_gyakugen(N, (int) m, bigmod)));
    }
    cout << ans << endl;

    return 0;
}




