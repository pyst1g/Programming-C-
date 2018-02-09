// finish date: 2018/02/03
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

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


int main() {
    int N;
    cin >> N;
    vi a(N), b(N);
    ll asum = 0, bsum = 0;
    rep(i, N) {
        cin >> a[i];
        asum += a[i];
    }
    rep(i, N) {
        cin >> b[i];
        bsum += b[i];
    }
    if (asum > bsum) {
        cout << "No" << endl;
        return 0;
    }
    ll can = bsum - asum;
    ll acount = 0, bcount = 0;
    rep(i, N) {
        if (a[i] > b[i]) bcount += a[i] - b[i];
        else if (a[i] < b[i]) {
            acount += ((ll)b[i] - a[i] + 1) / 2;
            if (((ll)b[i] - a[i]) % 2 == 1) bcount++;
        }
    }
    if ((can-acount)*2==(can-bcount)&&acount<=can&&bcount<=can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}

