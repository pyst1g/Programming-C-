// finish date: 2018/04/21

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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (X > Y) {
        swap(X, Y);
        swap(A, B);
    }
    if (A + B <= C * 2) {
        cout << A * X + B * Y << endl;
    } else {
        cout << min(C * 2 * Y, C * 2 * X + B * (Y - X));
    }

    return 0;
}