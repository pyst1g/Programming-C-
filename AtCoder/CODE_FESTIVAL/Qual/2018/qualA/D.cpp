// finish date: 2018/09/23
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

int main() {
    int D, F, T, N;
    cin >> D >> F >> T >> N;
    N++;
    T--;
    vi X(N);
    X[0] = 0;
    FOR(i, 1, N) {
        cin >> X[i];
    }
    vi cnt(N, 0);
    cnt[0] = 1;
    int ans = 0;
    rep(i, N) {
        //cout << distance(X.begin(), lower_bound(X.begin(), X.end(), X[i] + F - T)) << endl;
        if (i >= 2) cnt[i] = add(cnt[i], cnt[i - 1]);
        int disA = distance(X.begin(), lower_bound(X.begin(), X.end(), X[i] + F - T)) - i;
        int disB = distance(X.begin(), upper_bound(X.begin(), X.end(), X[i] + F)) - i;
        if (i + disA < N) cnt[i + disA] = add(cnt[i + disA], mul(cnt[i], modpow(2, disA - 1)));
        if (i + disB < N) cnt[i + disB] = sub(cnt[i + disB], mul(cnt[i], modpow(2, disA - 1)));
        else if (X[i] + F >= D) ans = add(ans, mul(cnt[i], modpow(2, disA - 1)));
    }
    cout << ans << endl;

    return 0;
}

