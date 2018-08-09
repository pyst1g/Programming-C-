// finish date: 2018/02/09

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
    vi Ax(N), Ay(N), Bx(N), By(N);
    rep(i, N) {
        cin >> Ax[i] >> Ay[i];
    }
    rep(i, N) {
        cin >> Bx[i] >> By[i];
    }
    double centerAx = 0, centerAy = 0, centerBx = 0, centerBy = 0;
    rep(i, N) {
        centerAx += (double) Ax[i] / N;
        centerAy += (double) Ay[i] / N;
        centerBx += (double) Bx[i] / N;
        centerBy += (double) By[i] / N;
    }
    double distance_max_A = 0, distance_max_B = 0;
    rep(i, N) {
        distance_max_A = max(distance_max_A, sqrt(pow(Ax[i] - centerAx, 2) + pow(Ay[i] - centerAy, 2)));
        distance_max_B = max(distance_max_B, sqrt(pow(Bx[i] - centerBx, 2) + pow(By[i] - centerBy, 2)));
    }
    printf("%.6f\n", distance_max_B / distance_max_A);

    return 0;
}


