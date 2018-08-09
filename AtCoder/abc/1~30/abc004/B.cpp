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
    vector<vector<string>> c(4,vector<string>(4));
    rep(i, 4) {
        rep(j, 4) cin >> c[i][j];
    }
    string temp;
    rep(i, 4) {
        rep(j, 2) {
            swap(c[j][i],c[3-j][i]);
//            temp = c[j][i];
//            c[j][i] = c[3-j][i];
//            c[3-j][i] = temp;
        }
    }
    rep(i, 4) {
        rep(j, 2) {
            swap(c[i][j],c[i][3-j]);
//            temp = c[i][j];
//            c[i][j] = c[i][3-j];
//            c[i][3-j] = temp;
        }
    }
    rep(i,c.size()){
        rep(j,c[i].size()){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
