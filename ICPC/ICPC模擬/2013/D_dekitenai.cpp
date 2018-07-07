// finish date: 2018/07/05
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
typedef vector<long double> vd;
typedef vector<vector<long double>> vvd;
typedef vector<vector<vector<long double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


ll prim(int N, vector<vector<pii> > edge) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<bool> used(N, false);
    pq.push(pii(0, 0));
    ll total = 0;
    while (!pq.empty()) {
        int dis, t;
        tie(dis, t) = pq.top();
        pq.pop();
        if (used[t]) continue;
        used[t] = true;
        total += dis;
        for (auto e: edge[t]) {
            if (!used[e.second]) pq.push(e);
        }
    }
    return total;
}

struct Union_Find {
    vi parent;
    vi sizes;
    int setnum = 0;

    Union_Find(int n) : parent(n), sizes(n, 1) {
        rep(i, n) parent[i] = i;
        setnum = n;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);

        parent[y] = x;
        sizes[x] += sizes[y];
        setnum--;

    }

    bool isSame(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sizes[find(x)];
    }
};

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        vvi h(N, vi(2));
        vvi abc(M, vi(3));
        rep(i, N) {
            cin >> h[i][0];
            h[i][1] = i;
        }
        rep(i, M) {
            cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
            abc[i][0]--;
            abc[i][1]--;
        }
        map<int, int> numh;
        rep(i, N) {
            numh[h[i][0]]++;
        }

        sort(h.rbegin(), h.rend());
        map<int, int> tr;
        rep(i, N) {
            tr[h[i][1]] = i;
        }

        rep(i, M) {
            rep(j, 2) {
                abc[i][j] = tr[abc[i][j]];
            }
        }
        /*
        rep(i,N){
                rep(j,3){
                        cout<<abc[i][j] << " ";
                }
                cout<<endl;
        }*/


        vvi dist(N, vi(N, INT_MAX));
        Union_Find uf(N);
        rep(i, M) {
            int a = abc[i][0];
            int b = abc[i][1];
            int c = abc[i][2];
            //edge[a].push_back(make_pair(c,b));
            //edge[b].push_back(make_pair(c,a));
            dist[a][b] = c;
            dist[b][a] = c;
        }
        //cout<<dist.size();//<<" "<<dist[0].size();
        rep(i, N) dist[i][i] = 0;

        vector<bool> isUF(N, false);

        rep(i, N) {
            rep(j, i) {
                if (dist[i][j] != INT_MAX) {
                    uf.unite(i, j);
                }
            }
            if (uf.setnum == N - i) isUF[i] = true;
        }
        if (!isUF[N - 1]) {
            cout << 0 << endl;
            continue;
        }

        int idx = 0;
        for (int i = N - 1; i > 0; i--) {
            if (!isUF[i]) {
                int now = h[i][0];
                int now_idx = i;
                idx = i;
                while (idx < N-1 && h[idx][0] == h[idx + 1][0]) idx++;
                idx++;
                while (idx < N-1 && h[idx][0] == h[idx + 1][0]) idx++;
                idx++;
                idx = min(idx, N);
                break;
            }
        }
//        rep(i,N) cout<<h[i][0]<<endl;



        ll ans = 0;
//        idx = 9;
        if (idx != 0) {
            vector<vector<pii> > edge(idx);
            rep(i, idx) {
                rep(j, idx) {
                    if (dist[i][j] != INT_MAX) {
                        edge[i].push_back(make_pair(dist[i][j], j));
                        edge[j].push_back(make_pair(dist[i][j], i));
                    }
                }
            }
            ans += prim(idx, edge);
        }
        if (idx == 0) idx++;
        FOR(i, idx, N) {
            int mi = INT_MAX;
            rep(j, i) {
                mi = min(mi, dist[i][j]);
            }
            //cout<<i<<" "<<mi<<endl;
            ans += mi;
        }

        cout << ans << endl;

    }

    return 0;
}

