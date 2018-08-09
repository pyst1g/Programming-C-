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
    int N;
    vector<int> v(6);
    cin >> N;
    int quotient = N/5;
    int remainder = N%5;
    int topnum = quotient%+6+1;
    rep(i,6){
        v[i] = (topnum+i) % 7 + (topnum+i) / 7;
    }
    rep(i,remainder) swap(v[i],v[i+1]);
    rep(i,6) cout << v[i];
    cout << endl;
    return 0;
}
