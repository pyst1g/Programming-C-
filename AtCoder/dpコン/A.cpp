// finish date: 2019/2/14

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
    int N;
    cin >> N;
    vi h(N);
    rep(i, N) cin >> h[i];
    vi cost(N, INF);
    cost[0] = 0;
    rep(i, N - 2) {
        cost[i + 1] = min(cost[i + 1], cost[i] + abs(h[i + 1] - h[i]));
        cost[i + 2] = min(cost[i + 2], cost[i] + abs(h[i + 2] - h[i]));
    }
    //こーなけーす
    cost[N - 1] = min(cost[N - 1], cost[N - 2] + abs(h[N - 1] - h[N - 2]));
    cout << cost[N - 1] << endl;

    return 0;
}