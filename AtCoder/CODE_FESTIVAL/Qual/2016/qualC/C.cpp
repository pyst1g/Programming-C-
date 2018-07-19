// finish date: 2018/07/19
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

int main() {
    int N;
    cin >> N;
    vi T(N);
    vi A(N);
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];
    vi h(N, -1);
    if(N==1 &&A[0] != T[0]){
        cout<<0<<endl;
        return 0;
    }
    h[0] = T[0];
    FOR(i, 1, N) {
        if (T[i] != T[i - 1]) h[i] = T[i];
    }
    h[N - 1] = A[N - 1];
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] < h[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (A[i] != A[i + 1]) {
            if (h[i] != -1 && h[i] != A[i]) {
                cout << 0 << endl;
                return 0;
            } else {
                h[i] = A[i];
                if (h[i] > T[i]) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    int ans = 1;
    rep(i, N) {
        if (h[i] != -1) continue;
        ans = mul(ans, min(T[i], A[i]));
    }
    cout << ans << endl;

    return 0;
}

