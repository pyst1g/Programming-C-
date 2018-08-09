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
    int in;
    map<int, int> C;
    rep(i, N) {
        cin >> in;
        C[in]++;
    }
    int mulCount;
    for (auto itr1 = C.begin(); itr1 != C.end(); itr1++) {
        mulCount = itr1->second - 1;
        for (auto itr2 = C.begin(); itr2 != itr1; itr2++) {
            if (itr1->first % itr2->first==0){
                mulCount += itr1->second;
            }
        }
    }

    return 0;
}
