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
    bitset<4> b(N);
    vector<int> v;
    v.reserve(4);
    rep(i, 4) if (b[i] == 1) v.emplace_back(pow(2,i));
    cout << v.size() << endl;
    rep(i,v.size()) cout << v[i] << endl;

    return 0;
}
