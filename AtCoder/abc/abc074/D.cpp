// finish date: 2018/05/20

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
    int N;
    cin >> N;
    vvi A(N, vi(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    vvi dist(N, vi(N, INF));
    vvi flag(N, vi(N, false));
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                if (A[i][k] + A[k][j] == A[i][j] && i != k && j != k){
                    flag[i][j] = true;
                }
            }
        }
    }
    ll sum = 0;
    rep(i, N) {
        rep(j, N) {
            if (!flag[i][j]) sum += A[i][j];
        }
    }
    cout << sum / 2 << endl;

    return 0;
}


