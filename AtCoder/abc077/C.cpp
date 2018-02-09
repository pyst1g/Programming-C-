// finish date: 2018/02/05

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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    int N;
    cin >> N;
    vi A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    //B[i]<C[j]となるjの個数をBC[i]に格納(後に累積和)
    vl BC(N, 0);
    int idxB = 0, idxC = 0;
    while (idxB < N && idxC < N) {
        if (B[idxB] < C[idxC]) {
            BC[idxB] = N - idxC;
            idxB++;
        } else {
            idxC++;
        }
    }
    //後ろから累積和
    for (int i = N - 2; i >= 0; i--) {
        BC[i] += BC[i + 1];
    }
    ll ans = 0;
    int idxA = 0;
    idxB = 0;
    while (idxA < N && idxB < N) {
        if (A[idxA] < B[idxB]) {
            ans += BC[idxB];
            idxA++;
        } else {
            idxB++;
        }
    }

    cout << ans << endl;

    return 0;

}

