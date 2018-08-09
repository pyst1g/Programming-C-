// finish date: 2018/01/08
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
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if((double)B/A==(double)D/C) cout<<"DRAW"<<endl;
    else if((double)B/A>(double)D/C) cout<<"TAKAHASHI"<<endl;
    else cout<<"AOKI"<<endl;

    return 0;
}
