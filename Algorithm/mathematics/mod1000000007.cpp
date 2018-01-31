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

//足し算
int add(int a, int b) {
    return (a + b) % bigmod;
}

//引き算
int sub(int a, int b) {
    return (a - b + bigmod) % bigmod;
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
        int d = gyakugen(a, p, b / 2);
        return mul(d, d);
    } else {
        return mul(a, gyakugen(a, p, b - 1));
    }
}


//nやkが大きな場合、使ってはならない(nCkをO(1)で求めるようにプログラムを適切に変更する。
int nCk_gyakugen(int n, int k, int p = bigmod) {
    if (n == 0) return (k == 0) ? 1 : 0;
    if (n < k) return 0;
    int denominator = 1;
    int molecule = 1;
    rep(i, k) {
        denominator = mul(denominator, n - i);
        molecule = mul(molecule, i + 1);
    }
    return mul(denominator, gyakugen(molecule));
}