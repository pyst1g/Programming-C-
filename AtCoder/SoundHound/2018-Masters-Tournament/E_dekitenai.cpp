// finish date: 2018/07/25
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


void check(int val0, vector<vector<pii>> edge, int n) {


    return;
}


int main() {
    int n, m;
    cin >> n >> m;
    vi u(m), v(m), s(m);
    vector<vector<pii>> edge(n);
    rep(i, m) {
        cin >> u[i] >> v[i] >> s[i];
        u[i]--;
        v[i]--;
        edge[u[i]].push_back(pii(s[i], v[i]));
        edge[v[i]].push_back(pii(s[i], u[i]));
    }
    vi parity(n, -1);
    vi value(n, INT_MIN);
    value[0] = 0;
    parity[0] = 0;
    bool isBipatate = true;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int e;
        e = que.front();
        que.pop();
        for (pii t:edge[e]) {
            int dist = t.first;
            int to = t.second;
            if (parity[to] == -1) {
                que.push(to);
                parity[to] = 0 ^ parity[e];
                value[to] = dist - value[e];
            } else {
                if (parity[to] != parity[e]) {
                    if (value[to] != dist - value[e]) {
                        cout << 0 << endl;
                        return 0;
                    }
                } else {
                    //非二部グラフの場合
                    int diff = dist - (value[to] + value[e]);
                    if (diff % 2 != 0) {
                        cout << 0 << endl;
                    } else {
                        if (parity[to] == 1) {
                            value[0] += diff / 2;
                        } else {
                            value[0] -= diff / 2;
                        }
                        check(value[0], edge, n);
                    }
                    return 0;
                }
            }
        }
    }


    return 0;
}

