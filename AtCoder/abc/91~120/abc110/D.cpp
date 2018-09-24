// finish date: 2018/09/24
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>>
        vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>>
        vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int N, M;
vi fact;


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


int main() {
    cin >> N >> M;
    map<int, int> mp = p_fact(M);
    fact = vi(N + 50, 0);
    fact[0] = 1;
    FOR(i, 1, fact.size()) {
        fact[i] = mul(fact[i - 1], i);
    }
    int ans = 1;
    for (auto e:mp) {
        ans = mul(ans, nHk(N, e.second));
    }
    cout << ans << endl;

    return 0;
}

