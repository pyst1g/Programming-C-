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
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> rank(3, 2);
    if (A == max(A, max(B, C))) rank[0] = 1;
    else if (B == max(A, max(B, C))) rank[1] = 1;
    else if (C == max(A, max(B, C))) rank[2] = 1;
    if (A == min(A, min(B, C))) rank[0] = 3;
    else if (B == min(A, min(B, C))) rank[1] = 3;
    else if (C == min(A, min(B, C))) rank[2] = 3;

    rep(i, 3) cout << rank[i] << endl;


    return 0;
}
