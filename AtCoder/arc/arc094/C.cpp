// finish date: 2018/04/07

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
    vi val(3);
    cin >> val[0] >> val[1] >> val[2];
    sort(val.begin(), val.end());
    int ans = 0;
    ans += (val[2] - val[0]) / 2;
    ans += (val[2] - val[1]) / 2;
    if (val[0] % 2 == val[1] % 2 && val[1] % 2 == val[2] % 2) {
        cout << ans << endl;
    } else if (val[2] % 2 != val[0] % 2 && val[2] % 2 != val[1] % 2) {
        cout << ans + 1 << endl;
    } else {
        cout << ans + 2 << endl;
    }

    return 0;
}
