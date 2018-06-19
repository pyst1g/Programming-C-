// finish date: 2018/05/12
#include <bits/stdc++.h>


using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>


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

int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> mp1, mp2;
    vi p(N);
    rep(i, N) {
        cin >> p[i];
        mp1[p[i]] = i + 1;
        mp2[i + 1] = p[i];
    }
    int x, y;
    Union_Find uf(N+1);
    rep(i, M) {
        cin >> x >> y;
        uf.unite(x, y);
    }

    int c = 0;
    rep(i, N) {
        if (uf.isSame(i + 1, p[i])) c++;
    }
    cout << c << endl;

    return 0;
}