// finish date: 2018/01/14
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 1000000000

vector<vector<int>> b, c, field;


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}


int main() {
    int K;
    cin >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];
    if (A[K - 1] != 2) {
        cout << -1 << endl;
        return 0;
    }
    int maval = 0;
    rep(i, K) {
        maval = max(maval, A[i]);
    }
    long long int mi = A[0] * ((maval + A[0] - 1) / A[0]);
    long long int  ma = 3;
    for (int i = K - 2; i >= 0; i--) {
        if (A[i] > ma) {
            cout << -1 << endl;
            return 0;
        }
        ma = A[i] * ((ma + A[i]) / A[i]) - 1;
    }
    cout << mi << " " << ma << endl;
    return 0;
}
