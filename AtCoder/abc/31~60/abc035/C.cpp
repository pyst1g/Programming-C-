// finish date: 2018/01/17
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
#define INF 500000000

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> ban(N, 0);
    int l, r;
    rep(i, Q) {
        cin >> l >> r;
        l--;
        r--;
        ban[l]++;
        if (r != N - 1) ban[r + 1]++;
    }
    FOR(i, 1, N) ban[i] += ban[i - 1];
    rep(i, N) cout << to_string(ban[i] % 2);
    cout<<endl;

    return 0;
}
