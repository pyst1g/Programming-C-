// finish date: 2018/02/26

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


struct E {
    int to, distance;

    E(int t, int d) {
        to = t;
        distance = d;
    }
};

vi x;
vector<vector<E>> EL, ER;
vb useL, useR;

bool dfs(vector<vector<E>> &edges, int node, vb &use) {
    if (use[node]) return true;
    use[node] = true;
    if (x[node] == INT_MAX) x[node] = 0;
    bool flag = true;
    for (E e:edges[node]) {
        int newD = x[node] + e.distance;
        if (x[e.to] != INT_MAX && x[e.to] != newD) return false;
        x[e.to] = newD;
        flag &= dfs(EL, e.to, useL);
        flag &= dfs(ER, e.to, useR);
    }
    return flag;
}


int main() {
    int N, M;
    cin >> N >> M;
    if (M == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    vi L(M), R(M), D(M);
    EL = vector<vector<E>>(N);
    ER = vector<vector<E>>(N);
    x = vi(N, INT_MAX);
    useL = vb(N, false);
    useR = vb(N, false);
    rep(i, M) {
        cin >> L[i] >> R[i] >> D[i];
        L[i]--;
        R[i]--;
        EL[R[i]].emplace_back(E(L[i], -D[i]));
        ER[L[i]].emplace_back(E(R[i], D[i]));
    }
    rep(i, N) {
        bool con1 = dfs(EL, i, useL);
        bool con2 = dfs(ER, i, useR);
        if (!(con1 && con2)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;


}



