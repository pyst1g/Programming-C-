// finish date: 2018/03/14

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
    int H, W;
    cin >> H >> W;
    vs A(H);
    rep(i, H) cin >> A[i];
    int shape = 0;
    rep(i, H) rep(j, W) if (A[i][j] == '#') shape++;
    if (shape != H + W - 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    int posx = 0, posy = 0;
    while (posx == W - 1 && posy == H - 1) {
        if (posx != W - 1 && A[posy][posx + 1]) {
            posx++;
        } else if (posy != H - 1 && A[posy + 1][posx]) {
            posy++;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;

    return 0;
}