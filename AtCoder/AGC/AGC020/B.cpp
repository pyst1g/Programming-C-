// finish date: 2018/02/23

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
    vl A(K);
    rep(i, K) cin >> A[i];

    reverse(A.begin(), A.end());
    if (A[0] != 2) {
        cout << -1 << endl;
        return 0;
    }
    ll mi = 2, ma = 3;
    FOR(i, 1, K) {
        if (ma / A[i] - (mi - 1) / A[i] == 0) {
            cout << -1 << endl;
            return 0;
        } else {
            mi = (ll) A[i] * ((mi + A[i] - 1) / A[i]);
            ma = (ll) A[i] * (ma / A[i] + 1) - 1;
        }
    }
    cout << mi << " " << ma << endl;


    return 0;
}



