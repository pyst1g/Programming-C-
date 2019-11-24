// finish date: 2019/3/17

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
    vi C;
    int c;
    cin >> c;
    c--;
    C.push_back(c);
    int ma = c;
    rep(i, N - 1) {
        cin >> c;
        c--;
        if (C[C.size() - 1] != c) C.push_back(c);
        ma = max(ma, c);
    }
    N = C.size();
    vi color(ma + 1, 0);
    vi cnt(N, 0);
    cnt[0] = 1;
    color[C[0]] = cnt[0];
    FOR(i, 1, N) {
        cnt[i] = add(cnt[i - 1], color[C[i]]);
        color[C[i]] = add(color[C[i]], cnt[i - 1]);
    }

    cout << cnt[N - 1] << endl;

    return 0;
}
