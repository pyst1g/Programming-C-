// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>

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
    string S, T;
    string str = "@atcoder";
    cin >> S >> T;
    bool con1, con2, con3;
    rep(i, S.length()) {
        con1 = S[i] == T[i];
        con2 = S[i] == '@' && isExist(T[i], str);
        con3 = T[i] == '@' && isExist(S[i], str);
        if (!(con1 || con2 || con3)) {
            cout << "You will lose" << endl;
            return 0;
        }
    }
    cout << "You can win" << endl;
    return 0;
}
