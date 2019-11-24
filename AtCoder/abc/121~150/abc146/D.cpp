// finish date: 2019/11/24

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
const int INF = 1000000007;
const long long INFll = 100000000000000000;


vvi G;
map<pii, int> edge_i, edge_color;
vb isPass;

void dfs(int node) {
    if (isPass[node]) return;
    isPass[node] = true;
    int skip = -1;
    rep(i, G[node].size()) {
        if (edge_color[pii(node, G[node][i])] != 0) {
            skip = edge_color[pii(node, G[node][i])];
        }
    }

    int c = 1;
    rep(i, G[node].size()) {
        if (c == skip) c += 1;
        if (edge_color[pii(node, G[node][i])] == 0) {
            edge_color[pii(node, G[node][i])] = c;
            edge_color[pii(G[node][i], node)] = c;
            dfs(G[node][i]);
            c++;
        }
    }
}


int main() {
    int N;
    cin >> N;
    vvi ab(N - 1, vi(2));
    G = vvi(N);
    isPass = vb(N, false);

    rep(i, N - 1) {
        cin >> ab[i][0] >> ab[i][1];
        ab[i][0]--;
        ab[i][1]--;
        G[ab[i][0]].push_back(ab[i][1]);
        G[ab[i][1]].push_back(ab[i][0]);
        edge_i[pii(ab[i][0], ab[i][1])] = i;
        edge_i[pii(ab[i][1], ab[i][0])] = i;
        edge_color[pii(ab[i][1], ab[i][0])] = -1;
        edge_color[pii(ab[i][1], ab[i][0])] = -1;
    }
    int color = 0;
    rep(i, N) {
        color = max(color, (int) G[i].size());
    }
    dfs(0);
    cout << color << endl;
    rep(i, N - 1) {
        cout << edge_color[pii(ab[i][1], ab[i][0])] << endl;
    }


    return 0;
}
