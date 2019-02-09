// finish date: 2018/09/29

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
    int n;
    cin >> n;
    vector<pair<int, int>> c1(100001), c2(100001);
    rep(i, 100001) {
        c1[i].second = i;
        c2[i].second = i;
    }
    rep(i, n) {
        int v;
        cin >> v;
        if (i % 2 == 0) c1[v].first++;
        else c2[v].first++;
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    reverse(c1.begin(), c1.end());
    reverse(c2.begin(), c2.end());
    if (c1[0].second != c2[0].second) {
        cout << n - c1[0].first - c2[0].first;
    } else {
        cout<<min(n - c1[0].first - c2[1].first,n - c1[1].first - c2[0].first);
    }

    return 0;
}

