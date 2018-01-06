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
    string S;
    int N;
    cin >> S >> N;
    int l, r;
    string str;
    rep(i, N) {
        str = "";
        cin >> l >> r;
        FOR(j,l-1,r){
            str = S[j] + str;
        }
        S = S.substr(0,l-1) + str + S.substr(r);
    }
    cout << S << endl;


    return 0;
}
