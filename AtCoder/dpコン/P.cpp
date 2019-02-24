// finish date: 2019/2/24

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

//足し算
int add(int a, int b) {
    return (int) (((ll) a + b + bigmod) % bigmod);
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}


vb used;
vector<set<int>> edge;
vector<pii> cnt;

pii dfs(int node) {
    if (used[node]) return cnt[node];
    used[node] = true;
    int w = 1, b = 1;
    for (int e:edge[node]) {
        if (!used[e]) {
            pii p = dfs(e);
            w = mul(w, add(p.first, p.second));
            b = mul(b, p.first);
        }
    }
    return pii(w, b);
}

int main() {
    int N;
    cin >> N;
    used = vb(N, false);
    edge = vector<set<int>>(N);
    cnt = vector<pii>(N);
    rep(i, N - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].insert(y);
        edge[y].insert(x);
    }
    pii p = dfs(0);
    cout << add(p.first, p.second) << endl;

    return 0;
}