// finish date: 2018/08/04
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


struct Union_Find {
    vector<int> parent;
    vector<int> sizes;
    vector<set<int>> group;
    int setnum = 0;

    Union_Find(int n) : parent(n), sizes(n, 1), group(n) {
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
        for (auto i:group[y]) group[x].insert(i);
        group[x].insert(y);
        group[y].clear();
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
    int N, Q;
    cin >> N >> Q;
    int type, u, v;
    set<pii> st;
    Union_Find E(N), C(N);
    rep(i, Q) {
        cin >> type >> u >> v;
        u--, v--;
        if (type == 1) {
            st.insert(pii(u, v));
            st.insert(pii(v, u));
            E.unite(u, v);
        }
        if (type == 2) {
            for (auto e:E.group[E.find(u)]) {
                C.unite(E.find(u), e);
            }
            E.group[E.find(u)].clear();
        }
        if (type == 3) {
            if (st.count(pii(u, v)) || C.isSame(u, v)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

