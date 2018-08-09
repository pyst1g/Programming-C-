// finish date: 2018/01/09
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

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    int a, b;
    cin >> n;
    vector<int> v(1000002, 0);
    rep(i, n) {
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }
    FOR(i, 1, v.size() - 1) v[i] += v[i - 1];
    int ma = INT_MIN;
    rep(i, v.size() - 1) {
        ma = max(ma, v[i]);
    }
    cout << ma << endl;

    return 0;
}



