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


//fact定義
//fact = vi(, 0);
//fact[0] = 1;
//FOR(i, 1, fact.size()) {
//fact[i] = mul(fact[i - 1], i);
//}


//足し算
int add(int a, int b) {
    return (int) (((ll) a + b + bigmod) % bigmod);
}

//引き算
int sub(int a, int b) {
    return (int) (((ll) a - b + bigmod) % bigmod);
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int modpow(int a, int b) {
    if (b == 0) return 1;
    int temp = modpow(a, b / 2);
    if (b % 2 == 1) return mul(mul(temp, temp), a);
    else {
        return mul(temp, temp);
    }
}


//割り算(分母だけ)  -  逆元(求めたい数とbigmodを渡す)
int divide(int a, int p = bigmod, int b = -1) {
    if (b < 0) b = p - 2;  //int gyakugen(int a, int p, int b = p - 2とできなかったため。)
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        int d = divide(a, p, b / 2);
        return mul(d, d);
    } else {
        return mul(a, divide(a, p, b - 1));
    }
}

//nやkが大きな場合nCkをO(1)で求めるようにプログラムを適切に変更する。
int nCk_gyakugen(int n, int k, int p = bigmod) {
    if (k == 0) return 1;
    if (n == 0) 0;
    if (n < k) return 0;
    int denominator = fact[n];
    int molecule1 = fact[k];
    int molecule2 = fact[n - k];
    return mul(denominator, mul(divide(molecule1), divide(molecule2)));
}


//重複組み合わせ
int nHk(int n, int k) {
    return nCk_gyakugen(n + k - 1, k);
}

//行列積(mod)　X*Y
vvi matrix_mul(vvi X, vvi Y) {
    vvi A(X.size(), vi(Y[0].size(), 0));
    rep(i, X.size()) rep(j, Y[0].size()) rep(k, X[0].size()) A[i][j] = add(A[i][j], mul(X[i][k], Y[k][j]));
    return A;
}

//行列累乗 a^K
//a:行列 N:aの行(列)数 K:何乗するか
vvi modpowM(vvi a, int N, ll K) {
    int k = 1;
    vvvi A;
    A.push_back(a);
    while ((1LL << k) <= K) {
        A.push_back(matrix_mul(A[k - 1], A[k - 1]));
        k++;
    }

    vvi mat(N, vi(N, 0));
    rep(i, N) mat[i][i] = 1;
    rep(i, k) {
        if (K & (1LL << i)) {
            mat = matrix_mul(mat, A[i]);
        }
    }
    return mat;
}