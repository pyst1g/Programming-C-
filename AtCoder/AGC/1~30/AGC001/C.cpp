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

vvi connect;

void memo(int t, vi &dist, int temp) {
    if (dist[t] != INF) return;
    dist[t] = temp;
    for (int i:connect[t]) {
        memo(i, dist, temp + 1);
    }

}

int main() {
    int N, K;
    cin >> N >> K;
    connect = vvi(N, vi());
    vi A(N), B(N);
    rep(i, N - 1) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        connect[A[i]].emplace_back(B[i]);
        connect[B[i]].emplace_back(A[i]);
    }
    int mi = INF;
    rep(i, N) {
        if (K % 2 == 1 && i == N - 1) continue;

        vi dist(N, INF);
        int c = 0;
        if (K % 2 == 0) {
            memo(i, dist, 0);

        } else {
            dist[B[i]] = 0;
            memo(A[i], dist, 0);
            dist[B[i]] = INF;
            memo(B[i], dist, 0);
        }
        rep(j, N) if (dist[j] > K / 2) c++;
        mi = min(mi, c);
    }
    cout << mi << endl;

    return 0;
}