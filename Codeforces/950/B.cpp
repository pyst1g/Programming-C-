// finish date: 2018/03/09

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


int main() {
    int n, m;
    cin >> n >> m;
    vi x(n);
    rep(i, n) cin >> x[i];
    vi y(m);
    rep(i, m) cin >> y[i];

    int valX = 0, valY = 0;
    int idxX = 0, idxY = 0;
    int ans = 0;
    while (!(idxX == n && idxY == m)) {
        if (valX < valY) {
            valX += x[idxX];
            idxX++;
        } else {
            valY += y[idxY];
            idxY++;
        }
        if (valX == valY) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}