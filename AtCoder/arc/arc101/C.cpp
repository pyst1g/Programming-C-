// finish date: 2018/09/04
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


int main() {
    int N, K;
    cin >> N >> K;
    vi minus;
    vi plus;
    rep(i, N) {
        int x;
        cin >> x;
        if (x == 0) K--;
        if (x > 0) plus.push_back(x);
        else minus.push_back(-x);
    }
    reverse(minus.begin(), minus.end());
    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }
    int mi = INT_MAX;
    rep(i, minus.size()) {
        if (i == K - 1) {
            mi = min(mi, minus[i]);
            break;
        }
        if (0 <= K - (i + 1) - 1 && K - (i + 1) - 1 < plus.size()) {
            mi = min(mi, minus[i] * 2 + plus[K - (i + 1) - 1]);
        }
    }

    rep(i, plus.size()) {
        if (i == K - 1) {
            mi = min(mi, plus[i]);
            break;
        }
        if (0 <= K - (i + 1) - 1 && K - (i + 1) - 1 < minus.size()) {
            mi = min(mi, plus[i] * 2 + minus[K - (i + 1) - 1]);
        }
    }

    cout << mi << endl;


    return 0;
}

