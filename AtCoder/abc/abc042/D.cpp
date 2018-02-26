// finish date: 2018/02/03

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
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000


vi fact;

//足し算
int add(int a, int b) {
    return (a + b) % bigmod;
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

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
    if (n == 0) 0;
    if (n < k) return 0;
//    int denominator = 1;
//    int molecule = 1;
//    rep(i, k) {
//        denominator = mul(denominator, n - i);
//        molecule = mul(molecule, i + 1);
//    }
//    return mul(denominator, divine(molecule));
    int denominator = fact[n];
    int molecule1 = fact[k];
    int molecule2 = fact[n-k];
    return mul(denominator,mul(divine(molecule1),divine(molecule2)));
}


int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    H--;
    W--;
    A--;
    B--;
    fact = vi(H + W + 1, 1);
    FOR(i, 1, fact.size()) fact[i] = mul(fact[i - 1], i);
    int ans = 0;
    rep(i, W - B) {
        ans = add(ans, mul(nCk_gyakugen((H - A - 1) + (B + i + 1), (H - A - 1)),
                           nCk_gyakugen(A + (W - B - 1 - i), A)));
    }

    cout << ans << endl;

    return 0;
}

