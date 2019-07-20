// finish date: 2018/12/15

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


int main() {
    string S;
    cin >> S;
    ll ans = 0;
    vi cntW(S.length(), 0);
    if (S[S.length() - 1] == 'W') cntW[S.length() - 1] = 1;
    for (int i = S.length() - 2; i >= 0; i--) {
        cntW[i] = cntW[i + 1];
        if (S[i] == 'W') cntW[i]++;
    }
    rep(i,S.length()){
        if(S[i]=='B') ans += cntW[i];
    }
    cout<<ans<<endl;

    return 0;
}


