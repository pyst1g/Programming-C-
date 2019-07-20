// finish date: 2018/02/24

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
    int N, M;
    cin >> N >> M;
    vb redPossibility(N, false);
    redPossibility[0] = true;
    vi ballNum(N, 1);
    int x, y;
    rep(i, M) {
        cin >> x >> y;
        x--;
        y--;
        ballNum[x]--;
        ballNum[y]++;
        if (redPossibility[x]) redPossibility[y] = true;
        if (ballNum[x] == 0) redPossibility[x] = false;
    }
    int c = 0;
    rep(i, N) if (redPossibility[i]) c++;
    cout << c << endl;

    return 0;
}



