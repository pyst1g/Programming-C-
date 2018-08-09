// finish date: 2018/01/16
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

vector<vector<int>> sv;

int calc(int men) {
    int S = sv[men].size();
    if (S == 0) return 1;
    int ma = -INF, mi = INF;
    rep(i, S) {
        ma = max(ma, calc(sv[men][i]));
        mi = min(mi, calc(sv[men][i]));
    }
    return ma + mi + 1;
}


int main() {
    int N;
    cin >> N;
    sv = vector<vector<int>>(N, vector<int>());
    int jousi;
    FOR(i, 2, N+1) {
        cin >> jousi;
        sv[jousi-1].emplace_back(i-1);
    }
    cout << calc(0) << endl;

    return 0;
}
