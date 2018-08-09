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
    string A,B;
    cin >> A>>B;
    string ans;
    if(A.length() > B.length()) ans = A;
    else ans = B;
    cout << ans << endl;
    return 0;

}
