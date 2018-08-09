// finish date: 2018/01/20
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
    reverse(S.begin(), S.end());
    int pos = 0;
    while (pos != S.length()) {
        if (S.substr(pos, 5) == "maerd") pos += 5;
        else if (S.substr(pos, 7) == "remaerd") pos += 7;
        else if (S.substr(pos, 5) == "esare") pos += 5;
        else if (S.substr(pos, 6) == "resare") pos += 6;
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
