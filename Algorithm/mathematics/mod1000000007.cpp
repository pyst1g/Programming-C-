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
    return (int)(((ll)a + b + bigmod) % bigmod);
}

//引き算
int sub(int a, int b) {
    return (int)(((ll)a - b + bigmod) % bigmod);
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
    int molecule2 = fact[n-k];
    return mul(denominator,mul(divide(molecule1),divide(molecule2)));
}


//重複組み合わせ
int nHk(int n, int k) {
    return nCk_gyakugen(n + k - 1, k);
}


//素因数分解
map<int, int> p_fact(int n) {
    map<int, int> mp;
    int i = 2;
    while (n >= i * i) {
        while (n % i == 0) mp[i]++, n /= i;
        i++;
    }
    if (n != 1) mp[n]++;
    return mp;
}