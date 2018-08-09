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


int main() {
    int N;
    cin >> N;
    N++;
    vi t(N);
    vi v(N);
    FOR(i, 1, N) {
        cin >> t[i];
        if (i != 0) t[i] += t[i - 1];
    }
    int sizeT = t[N - 1];
    FOR(i, 1, N) cin >> v[i];
    vd T(sizeT * 2 + 1, INF);
    //順方向
    rep(i, N - 1) {
        rep(j, t[i] * 2) {
            T[j] = min(T[j], v[i + 1] + (t[i] * 2 - j) * 0.5);
        }

        FOR(j, t[i] * 2, t[i + 1] * 2) {
            T[j] = min(T[j], (double) v[i + 1]);
        }

        FOR(j, t[i + 1] * 2, T.size()) {
            T[j] = min(T[j], v[i + 1] + (j - t[i + 1] * 2) * 0.5);
        }
    }

    rep(i, T.size()) {
        T[i] = min(T[i], i * 0.5);
        T[i] = min(T[i], sizeT - 0.5 * i);
    }

    double ans = 0;
    FOR(i, 1, T.size()) {
        ans += (T[i] + T[i - 1]) * 0.25;
//        ans += T[i] * 0.5;
//        if (T[i] > T[i - 1]) {
//            ans -= 0.125;
//        } else if (T[i] < T[i - 1]) {
//            ans += 0.125;
//        }
    }
    printf("%.4f\n", ans);


    return 0;
}

