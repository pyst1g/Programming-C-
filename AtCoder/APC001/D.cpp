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

int main() {
    ll cost = 0;
    int N, M;
    cin >> N >> M;
    Union_Find uf(N);
    vector<pair<ll, int>> a(N);
    ll in;
    rep(i, N) {
        cin >> in;
        a[i] = make_pair(in, i);
    }
    sort(a.begin(), a.end());
    int x, y;
    rep(i, M) {
        cin >> x >> y;
        uf.unite(x, y);
    }
    if(uf.setnum==1){
        cout<<0<<endl;
        return 0;
    }
    vb toujou(N, false);
    int count = 0;
    int toujoucount = 0;
    rep(i, N) {
        if (toujou[uf.find(a[i].second)]) {
            count++;
            if (count <= uf.setnum - 2) cost = cost + a[i].first;
        } else {
            toujoucount++;
            cost += a[i].first;
            toujou[uf.find(a[i].second)] = true;
        }
    }
    if (count >= uf.setnum - 2 && toujoucount == uf.setnum) cout << cost << endl;
    else cout << "Impossible" << endl;
    return 0;

}

