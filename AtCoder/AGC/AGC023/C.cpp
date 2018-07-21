// finish date: 2018/07/20
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;

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


//割り算  -  逆元(求めたい数とbigmodを渡す)
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

int frac(int a, int b) {
    return mul(a, divide(b));
}

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
    int N;
    cin >> N;
//    if(N == 2){
//        cout<<1<<endl;
//    }
    fact = vi(N);
    fact[0] = 1;
    FOR(i, 1, N) fact[i] = mul(fact[i - 1], i);
    vi A(N + 1, 0);
    int ans = 0;
    FOR(k, 1, N) {
        if (k - 1 < N - 1 - k) continue;
        A[k] = mul(nCk_gyakugen(k - 1, N - 1 - k), mul(fact[k], fact[N - 1 - k]));
        ans = add(ans, mul(sub(A[k], A[k- 1]), k));
    }
    cout << ans << endl;


    return 0;
}

