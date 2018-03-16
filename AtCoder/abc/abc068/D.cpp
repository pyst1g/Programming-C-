// finish date: 2018/03/10

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
    ll K;
    cin >> K;

    int N = 50;
    vl a(N, (N - 1) + K / N);
    rep(i, K % N) {
        a[i] += 1;
    }
    FOR(i, K % N, N) {
        a[i] -= K % N;
    }
    cout << N << endl;
    rep(i, N) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}