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
    int H, W;
    cin >> H >> W;
    vs A(H);
    rep(i, H) {
        cin >> A[i];
    }
    map<char, int> mp;
    rep(i, H) {
        rep(j, W) {
            mp[A[i][j]]++;
        }
    }

    int need4 = (H / 2) * (W / 2);
    int need2 = (H % 2) * (W / 2) + (H / 2) * (W % 2);
    int need1 = (H % 2) * (W % 2);

    for (auto element:mp) {
        char c;
        int e;
        tie(c, e) = element;
        need4 -= e / 4;
        e = e % 4;
        if (need4 < 0) {
            e += 4 * (-need4);
            need4 = 0;
        }
        need2 -= e / 2;
        e = e % 2;
        if (need2 < 0) {
            e += 2 * (-need2);
            need2 = 0;
        }
        need1 -= e;
        if (need1 < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}

