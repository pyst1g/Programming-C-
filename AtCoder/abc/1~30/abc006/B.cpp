// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>

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
    int n;
    cin >> n;
    vector<int> a(1000001);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    FOR(i, 4, 1000001) a[i] = (a[i - 1] + a[i - 2] + a[i - 3])% 10007;
    cout << a[n] << endl;


}
