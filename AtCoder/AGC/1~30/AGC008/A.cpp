// finish date: 2018/03/14

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
    int x, y;
    cin >> x >> y;
    if (x <= y) {
        if (x < 0 && y > 0) cout << abs(abs(y) - abs(x)) + 1 << endl;
        else cout << y - x << endl;
    } else {
        if ((ll) x * y > 0) cout << abs(abs(y) - abs(x)) + 2 << endl;
        else cout << abs(abs(y) - abs(x)) + 1 << endl;
    }

    return 0;
}