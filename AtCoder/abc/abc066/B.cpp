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
    S = S.substr(0, S.length() - 1);
    if (S.length() % 2 == 1) S = S.substr(0, S.length() - 1);
    while (S.substr(0, S.length() / 2) != S.substr(S.length() / 2, S.length() / 2)) {
        S = S.substr(0, S.length() - 2);
    }
    cout << S.length() << endl;
    return 0;
}
