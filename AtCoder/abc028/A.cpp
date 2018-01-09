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
    int N;
    cin >> N;
    if (N <= 59) cout << "Bad" << endl;
    else if (N <= 89) cout << "Good" << endl;
    else if (N <= 99) cout << "Great" << endl;
    else cout << "Perfect" << endl;

    return 0;
}
