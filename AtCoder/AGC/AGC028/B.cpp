// finish date: 2018/10/14

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


int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    int factN = 1;
    FOR(i, 1, N + 1) factN = mul(factN, i);
    vi E(N + 1, 0);
    FOR(i, 1, N + 1) {
        E[i] = mul(factN, divide(i));
        E[i] = add(E[i], E[i - 1]);
    }
    int ans = 0;
    rep(i, N) {
        ans = add(ans, mul(A[i], sub(E[i + 1], E[1])));
        ans = add(ans, mul(A[i], E[N - i]));
    }
    cout << ans << endl;


    return 0;
}

