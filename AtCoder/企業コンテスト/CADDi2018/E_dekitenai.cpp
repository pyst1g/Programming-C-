// finish date: 2018/12/22

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
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;

vi plus_operation(vi &v) {
    vi ret(v.size(), 0);
    int cnt2 = 0;
    FOR(i, 1, v.size()) {
        //ret[i] = ret[i - 1];
        if (v[i] / v[i - 1] < (1 << min(31, cnt2))) {
            cnt2 += (int) ceil(log2(sqrt((double) v[i - 1] / v[i]))) * 2;

            ret[i] = cnt2;
        } else {
            cnt2 = 0;
            ret[i] = 0;
        }
    }

    return ret;
}

/*
int calc_operation(vi &A, int m, int N) {
    int cnt = m; //反転分
    vi v1(m), v2(N - m);
    rep(i, N) {
        if (i < m) v1[i] = A[i];
        else v2[i - m] = A[i];
    }
    reverse(v1.begin(), v1.end());
    cnt += plus_operation(v1);
    cnt += plus_operation(v2);
    return cnt;
}*/

int main() {
    //入力と変数宣言
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    vi B = A;
    reverse(B.begin(), B.end());
    vi plus_cnt = plus_operation(A);
    vi minus_cnt = plus_operation(B);
    reverse(plus_cnt.begin(), plus_cnt.end());

    FOR(i, 1, N) {
        plus_cnt[i] += plus_cnt[i - 1];
        minus_cnt[i] += minus_cnt[i - 1];
    }
    reverse(plus_cnt.begin(), plus_cnt.end());
    reverse(minus_cnt.begin(), minus_cnt.end());
    rep(i, N - 1) {
        plus_cnt[i] = plus_cnt[i + 1];
        minus_cnt[i] = minus_cnt[i + 1];
    }
    plus_cnt[plus_cnt.size() - 1] = 0;
    rep(i, N) minus_cnt[i]++;
    int ans = min(plus_cnt[plus_cnt.size() - 1], minus_cnt[0]);
    FOR(i, 1, N) {
        ans = min(ans, plus_cnt[i] + minus_cnt[i - 1]);
    }
    cout << ans << endl;

    /*int l = 0, r = N + 2;
    int m = (l + r) / 2;
    while (l <= r) {
        plus_operation()

        calc_operation(A, m, N);
    }*/

    return 0;
}

