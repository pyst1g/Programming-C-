// finish date: 2019/07/20

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
    vi a(N), b(N, 0);
    vvi fac(N);
    FOR(i, 1, N + 1) {
        int j = i + i;
        while (j <= N) {
            fac[j - 1].emplace_back(i);
            j += i;
        }
    }
    rep(i, N) {
        cin >> a[i];
    }
    for (int i = N; i > 0; i--) {
        if ((a[i - 1] + b[i - 1]) % 2) {
            b[i - 1] = 1;
            for (int e: fac[i - 1]) {
                b[e - 1] = !b[e - 1];
            }
        } else {
            b[i - 1] = 0;
        }
    }
    vi pnt;
    int cnt = 0;
    rep (i, N) {
        if (b[i]) {
            pnt.emplace_back(i + 1);
            cnt++;
        }
    }
    cout << cnt << endl;
    rep(i, cnt) {
        cout << pnt[i] << " " << endl;
    }
    cout << endl;

    return 0;
}
