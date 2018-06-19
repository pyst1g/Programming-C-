// finish date: 2018/06/02
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    int A, B, N;
    string X;
    cin >> A >> B >> N >> X;
    rep(i, N) {
        if (X[i] == 'S') {
            A = max(A - 1, 0);
        } else if (X[i] == 'C') {
            B = max(B - 1, 0);
        } else {
            if (A >= B) {
                A = max(A - 1, 0);
            } else {
                B = max(B - 1, 0);
            }
        }
    }
    cout << A << endl;
    cout << B << endl;
    return 0;
}



