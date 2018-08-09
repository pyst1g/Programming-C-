// finish date: 2018/01/21
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


int main() {
    string S;
    cin >> S;
    vector<int> alpha(26, 0);
    rep(i, S.length()) alpha[S[i] - 'a'] = 1;
    rep(i, alpha.size()) {
        if (alpha[i] == 0) {
            cout << (char) ('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
