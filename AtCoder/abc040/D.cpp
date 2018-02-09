// finish date: 2018/02/04

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000


struct Union_Find {
    vector<int> parent;
    vector<int> sizes;
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

struct connect {
    int x, y, year;
};

struct query {
    int idx, x, year;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<connect> connects(M);
    int a, b, y;
    rep(i, M) {
        cin >> a >> b >> y;
        a--;
        b--;
        connects[i].x = a;
        connects[i].y = b;
        connects[i].year = y;
    }
    sort(connects.begin(), connects.end(), [](const connect &x, const connect &y) { return x.year > y.year; });
    int Q;
    cin >> Q;
    vector<query> queries(Q);
    int v, w;
    rep(i, Q) {
        cin >> v >> w;
        v--;
        queries[i].idx = i;
        queries[i].x = v;
        queries[i].year = w;
    }
    sort(queries.begin(), queries.end(), [](const query &x, const query &y) { return x.year > y.year; });
    Union_Find uf(N);
    vi ans(Q);
    int t_idx = 0;
    int t_year = (M > 0) ? connects[0].year : 0; //ここの0は適当(RE対策)
    rep(i, Q) {
        //Union Findの編成
        while (t_idx < M && t_year > queries[i].year) {
            uf.unite(connects[t_idx].x, connects[t_idx].y);
            t_idx++;
            if (t_idx < M) t_year = connects[t_idx].year;
        }
        ans[queries[i].idx] = uf.size(queries[i].x);
    }


    rep(i, Q) cout << ans[i] << endl;


    return 0;

}

