// finish date: 2019/06/30

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
    rep(i, N) cin >> a[i];

    map<int, int> check_is2;
    rep(i, N) check_is2[a[i]]++;
    if (check_is2.size() == 1) {
        if (a[0] == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if (check_is2.size() == 2) {
        if (N % 3 == 0 && check_is2[0] == N / 3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if (check_is2.size() == 3) {
        vi val(3);
        vi cnt(3);
        int i = 0;
        for (auto e:check_is2) {
            val[i] = e.first;
            cnt[i] = e.second;
            i++;
        }
        if (((val[0] ^ val[1]) == val[2]) && (cnt[0] == cnt[1]) && (cnt[1] == cnt[2])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }


    cout << "No" << endl;
    return 0;
}
