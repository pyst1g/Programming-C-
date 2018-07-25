// finish date: 2018/07/23
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
    vi a(N);
    int mi = INF;
    int ma = -1;
    map<int, int> mp;
    rep(i, N) cin >> a[i], mi = min(mi, a[i]), ma = max(ma, a[i]), mp[a[i]]++;
    int miCnt = mp[mi];
    int maCnt = mp[ma];
    if (ma - mi > 1) {
        cout << "No" << endl;
    } else if (maCnt == 1) {
        cout << "No" << endl;
    } else if (ma == mi) {
        if (ma == N - 1 || (1 <= ma && ma <= N / 2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (1 <= mi - miCnt + 1 && mi - miCnt + 1 <= maCnt / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}

