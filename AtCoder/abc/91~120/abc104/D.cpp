// finish date: 2018/08/07
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


int main() {
    string S;
    cin >> S;
    int N = S.length();
    vi pow3(N + 1, 0);
    pow3[0] = 1;
    FOR(i, 1, N + 1) {
        pow3[i] = pow3[i - 1];
        pow3[i] = mul(pow3[i], 3);
    }

    vi A(N, 0), C(N, 0), Q(N, 0);
    rep(i, N) {
        if (i > 0) A[i] = A[i - 1], C[i] = C[i - 1], Q[i] = Q[i - 1];
        if (S[i] == 'A') A[i]++;
        if (S[i] == 'C') C[i]++;
        if (S[i] == '?') Q[i]++;
    }

    int cnt = 0;
    FOR(i, 1, N - 1) {
        if (S[i] != 'B' && S[i] != '?') continue;
        int qa = (S[i] == '?') ? Q[i] - 1 : Q[i];
        int qc = Q[N - 1] - Q[i];
        int a = A[i];
        int c = C[N - 1] - C[i];

        int sideA = mul(a, pow3[qa]);
        if (qa != 0) {
            sideA = add(sideA, mul(qa, pow3[qa - 1]));
        }

        int sideC = mul(c, pow3[qc]);
        if (qc != 0) {
            sideC = add(sideC, mul(qc, pow3[qc - 1]));
        }

        cnt = add(cnt, mul(sideA, sideC));
    }
    cout << cnt << endl;

    return 0;
}

