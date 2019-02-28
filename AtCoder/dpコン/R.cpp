// finish date: 2019/2/28

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

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}


vvi matrix_mul(vvi X, vvi Y) {
    vvi A(X.size(), vi(Y[0].size(), 0));
    rep(i, X.size()) rep(j, Y[0].size()) rep(k, X[0].size()) A[i][j] = add(A[i][j], mul(X[i][k], Y[k][j]));
    return A;
}


vvi modpowM_sum(vvi a, int N, ll K) {
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

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vvi a(N, vi(N));
    rep(i, N) rep(j, N) cin >> a[i][j];
    vvi mat = modpowM_sum(a, N, K);
    int total = 0;
    rep(i, N) rep(j, N) total = add(total, mat[i][j]);
    cout << total << endl;


    return 0;
}