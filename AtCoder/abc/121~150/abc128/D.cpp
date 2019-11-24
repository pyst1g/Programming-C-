// finish date: 2019/10/30

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
    vi V(N);
    rep(i, N) {
        cin >> V[i];
    }
    int ma = 0;

    rep(l, N + 1) {
        FOR(r, l-1, N) {
            vi have;
            rep(i, l) {
                have.push_back(V[i]);
            }
            FOR(i, r + 1, N) {
                have.push_back(V[i]);
            }
            sort(have.begin(), have.end());
            if (have.size() > K) continue;
            int res = min(have.size(), K - have.size());
            int tmp = 0;

            rep(i, res) tmp += max(have[i], 0);
            FOR(i, res, have.size()) tmp += have[i];
            ma = max(ma, tmp);
        }
    }
    cout << ma << endl;

    return 0;
}
