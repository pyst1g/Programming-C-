// finish date: 2019/2/23

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
    int N, K;
    cin >> N >> K;
    vvi a(N, vi(2));
    rep(i, N) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    vi ans;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    //1ターン目
    rep(i, N) {
        a[i][0]--;
        ans.push_back(a[i][1]);
    }
    int tag = ans[ans.size() - 1];
    //2ターン目以降
    FOR(i, 2, K + 2) {
        rep(j, N) {
            if (a[j][1] != tag) {
                a[j][0]--;
                ans.push_back(a[j][1]);
            }
        }
        tag = ans[ans.size() - 1];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
    }
//    rep(i, N) {
//
//    }
    if (a[N - 1][0] >= 0) {
        cout << ans.size() << endl;
        rep(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}