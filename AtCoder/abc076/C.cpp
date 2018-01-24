// finish date: 2018/01/24
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define bigmod 1000000007
#define INF 500000000


int main() {
    string S, T;
    cin >> S >> T;
    for (int i = (int) S.length() - (int) T.length(); i >= 0; i--) {
        rep(j, T.length()) {
            if (!(S[i + j] == T[j] || S[i + j] == '?')) break;
            if (j == T.length() - 1) {
                S.replace(i, T.length(), T);
                replace(S.begin(), S.end(), '?', 'a');
                cout << S << endl;
                return 0;
            }
        }
    }
    cout << "UNRESTORABLE" << endl;


    return 0;
}

