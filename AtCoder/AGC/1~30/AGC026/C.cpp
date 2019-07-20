// finish date: 2018/07/14
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
    int N;
    string S;
    cin >> N >> S;
    ll ans = 0;

    map<pair<string, string>, int> que;
    string S1, S2;
    rep(k, 1 << N) {
        S1 = "";
        S2 = "";
        rep(i, N) {
            if (k & (1 << i)) S1 += S[i + N];
            else S2 += S[i + N];
        }
        que[make_pair(S1, S2)]++;
    }


    rep(k, 1 << N) {
        S1 = "";
        S2 = "";
        rep(i, N) {
            if (k & (1 << i)) S1 = S[i] + S1;
            else S2 = S[i] + S2;
        }
        ans += que[make_pair(S2, S1)];
    }

    cout << ans << endl;

    return 0;
}

