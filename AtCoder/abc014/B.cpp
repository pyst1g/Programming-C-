// finish date: 2018/01/06
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <limits>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int main() {
    int n,X;
    cin >> n>>X;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bitset<20> b(X);
    int ans = 0;
    rep(i,n) if(b[i] == 1) ans += a[i];
    cout << ans << endl;
    return 0;

}
