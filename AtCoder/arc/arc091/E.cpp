// finish date: 2018/03/13

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


int checkLIS(vector<int> a) {
    vi minVal(a.size() + 1, INF);
    minVal[0] = -INF;
    rep(i, a.size()) {
        *upper_bound(minVal.begin(), minVal.end(), a[i]) = a[i];
    }
    for (int i = minVal.size() - 1; i >= 0; i--) {
        if (minVal[i] != INF) return i;
    }
    return 0;
}


int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vi ans(N, -1);
    if (B > N) {
        cout << -1 << endl;
        return 0;
    }
    int a = 0;
    rep(i, B) ans[B - 1 - i] = i + 1;
    int tempIdx = B;
    a = 1;
    while (tempIdx != N) {
        int kosuu = max(min(a + 1 + N - tempIdx - A, B), 1);
        if (tempIdx + kosuu > N) {
            cout << -1 << endl;
            return 0;
        }
        FOR(i, tempIdx, min(tempIdx + kosuu, N)) {
            ans[2 * tempIdx + kosuu - 1 - i] = i + 1;
        }
        tempIdx += kosuu;
        a++;
    }
    int checkA = checkLIS(ans);
    reverse(ans.begin(), ans.end());
    int checkB = checkLIS(ans);
    reverse(ans.begin(), ans.end());
    if (checkA == A && checkB == B) {
        rep(i, N) cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}