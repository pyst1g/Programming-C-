// finish date: 2018/02/04
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000


int main() {
    int N;
    cin >> N;
    if (N < 20) {
        string in;
        rep(i, 20) {
            cout << i << endl;
            cin >> in;
            if (in == "Vacant") return 0;
        }
    }
    vector<string> A(N);
    int res;
    string s;
    cout << 0 << endl;
    cin >> s;
    if (s == "Vacant") return 0;
    A[0] = s;
    int l = 0, r = 0;
    int m = N / 2;
    int disL, disR;
    rep(i, 19) {
        cout << m << endl;
        cin >> s;
        if (s == "Vacant") return 0;
        A[m] = s;
        disL = (l < m) ? m - l : (m + N) - l;
        disR = (m < r) ? r - m : (r + N) - m;
        disL--;
        disR--;
        if ((A[m] == A[r] && disR % 2 == 0) || (A[m] != A[r] && disR % 2 == 1)) {
            l = m;

        } else {
            r = m;
        }
        m = (r > l) ? (r + l) / 2 : (r + N + l) / 2;
    }


    return 0;

}

