// finish date: 2018/01/21
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


int main() {
    int n;
    cin >> n;
    vector<int> count;
    vector<int> appear_min(26, INF);
    string S;
    rep(i, n) {
        cin >> S;
        count = vector<int>(26, 0);
        rep(j, S.length()) count[S[j] - 'a']++;
        rep(j, 26) appear_min[j] = min(appear_min[j], count[j]);
    }
    string ans = "";
    rep(i, 26) rep(j, appear_min[i]) ans += (char) (i + 'a');
    cout << ans << endl;
    return 0;
}
