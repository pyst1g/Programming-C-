// finish date: 2018/01/15
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000

vector<vector<int>> b, c, field;


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> d(N, vector<int>(N, INF));
    vector<int> a(M), b(M), c(M);
    rep(i, M) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        d[a[i]][b[i]] = c[i];
        d[b[i]][a[i]] = c[i];
    }
    rep(i, N) d[i][i] = 0;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<int> isMinD(M, false);
    rep(i, M) {
        if(c[i] == d[a[i]][b[i]]) isMinD[i]= true;
    }
    int count = 0;
    rep(i, M) if (!isMinD[i]) count++;
    cout << count << endl;

    return 0;
}
