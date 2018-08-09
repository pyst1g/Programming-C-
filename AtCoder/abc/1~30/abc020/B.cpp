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
    int A, B;
    cin >> A >> B;
    int b = B;
    int digitB = 0;
    while (b != 0) {
        b /= 10;
        digitB++;
    }
    int cat = A * (int)pow(10, digitB) + B;
    cout << cat * 2 << endl;


    return 0;
}
