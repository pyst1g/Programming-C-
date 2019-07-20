// finish date: 2018/03/16

#include <bits/stdc++.h>

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
    ll push_count = 0;
    vl A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    rep(i, N) {
        A[i] += push_count;
        push_count += ((A[i] + B[i] - 1) / B[i]) * B[i] - A[i];
    }
    cout << push_count << endl;


    return 0;
}