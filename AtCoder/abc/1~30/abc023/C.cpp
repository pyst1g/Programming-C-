// finish date: 2018/01/14
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

#define bigmod 1000000007
using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}


int main() {
    int R, C, K, N;
    cin >> R >> C >> K >> N;
    vector<int> r(N, 0), c(N, 0);
    vector<int> r_count(R, 0), c_count(C, 0);
    rep(i, N) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
        r_count[r[i]]++;
        c_count[c[i]]++;
    }
    vector<int> gyou(K + 1, 0), retu(K + 1, 0);
    rep(i, R) if (r_count[i] <= K) gyou[r_count[i]]++;
    rep(i, C) if (c_count[i] <= K) retu[c_count[i]]++;


    long count = 0;
    rep(i, K + 1) count += gyou[i] * retu[K - i];


    rep(i, N) {
        if (r_count[r[i]] + c_count[c[i]] == K) count--;
        if (r_count[r[i]] + c_count[c[i]] == K + 1) count++;
    }
    cout << count << endl;

    return 0;
}
