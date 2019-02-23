// finish date: 20199/2/14

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
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 998244353;//1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


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

vi fact;


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

int main() {
    string S;
    cin >> S;
    unsigned int N = S.length();
    fact = vi(N + 1);
    fact[0] = 1;
    FOR(i, 1, fact.size()) {
        fact[i] = mul(fact[i - 1], i);
    }
    int R = 0, B = 0;
    vvi dp(N + 1, vi(N + 1, 0));
    dp[0][0] = 1;
    rep(i, N) {
        switch (S[i]) {
            case '0':
                R += 2;
                break;
            case '1':
                R += 1;
                B += 1;
                break;
            case '2':
                B += 2;
                break;
            default:
                break;
        }
        rep(j, N) {
            if (j + 1 <= R) {
                dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
            }
            if ((i + 1) - j <= B) {
                dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
            }
        }
    }

    int ans = 0;
    rep(i, N + 1) {
        ans = add(ans, mul(dp[N][i], nCk_gyakugen(N, R - i)));
    }
    cout << ans << endl;

    return 0;
}