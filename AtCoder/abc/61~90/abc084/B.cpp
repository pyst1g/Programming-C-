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
    int A, B;
    string S;
    cin >> A >> B >> S;
    if (S.length() != A + B + 1) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, S.length()) {
        if (i == A) {
            if (S[i] != '-') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (!('0' <= S[i] && S[i] <= '9')) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
