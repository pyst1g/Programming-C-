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
    vi A(N);
    rep(i, N) cin >> A[i];
    if (A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    FOR(i, 1, N) {
        if (A[i] != 0 && A[i] != 1 && A[i] - A[i - 1] > 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll cost = 0;
    FOR(i, 1, N) {
        if (A[i] == 0) continue;
        if (A[i] == 1) cost++;
        else {
            if (A[i - 1] + 1 == A[i]) {
                cost++;
            } else {
                cost += A[i];
            }
        }
    }
    cout << cost << endl;

    return 0;
}


