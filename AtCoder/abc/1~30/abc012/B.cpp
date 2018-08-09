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
    int N;
    cin >> N;
    string hh, mm, ss;
    hh = to_string(N / 3600);
    N = N % 3600;
    mm = to_string(N / 60);
    N = N % 60;
    ss = to_string(N);
    if (hh.length() == 1) hh = "0" + hh;
    if (mm.length() == 1) mm = "0" + mm;
    if (ss.length() == 1) ss = "0" + ss;
    cout << hh << ":" << mm << ":" << ss << endl;
}
