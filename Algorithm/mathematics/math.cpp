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


//階乗
int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans *= i;
    }
    return ans;
}

//組みあわせ(階乗factをあらかじめ定義しておく)
int nCk(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}


//組み合わせ
int nCk(int n, int k) {
    if (k == 0) return 1;
    int ans = 1;
    FOR(i, 1, k + 1) {
        ans *= n;
        n--;
        ans /= i;
    }
    return ans;
}


//重複組み合わせ
int nHk(int n, int k) {
    return nCk(n + k - 1, k);
}


//最大公約数
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) {
        swap(a, b);
    }
    int r = 1; //0以外であれば何でも
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}




