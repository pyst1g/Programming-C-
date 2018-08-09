// finish date: 2018/02/08

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
    int W, N, K;
    cin >> W >> N >> K;
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vvi worth(K + 1, vi(W + 1, 0)); //i個画像を入れる場合、幅合計j
    int ma = 0;
    rep(k, N) {
        for (int i = min(k,K-1); i >= 0; i--) { //i=N+1ではない
            rep(j, W + 1) {
                if (worth[i][j] != 0 || (i == 0 && j == 0)) {
                    if (j + A[k] <= W) {
                        worth[i + 1][j + A[k]] = max(worth[i + 1][j + A[k]], worth[i][j] + B[k]);
                        ma = max(ma, worth[i + 1][j + A[k]]);
                    }
                }
            }
        }
    }
    cout << ma << endl;
    return 0;

    return 0;
}


