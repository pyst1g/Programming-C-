// finish date: 2018/02/09

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
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>



int main() {
    int N;
    cin >> N;
    int d;
    int ma = -INF;
    int maxIdx;
    FOR(i, 2, N + 1) {
        cout << "? " << 1 << " " << i << endl;
        cin >> d;
        if (d > ma) {
            ma = d;
            maxIdx = i;
        }
    }
    ma = -INF;
    FOR(i, 1, N + 1) {
        if (i == maxIdx) continue;
        cout << "? " << maxIdx << " " << i << endl;
        cin >> d;
        ma = max(ma, d);
    }
    cout << "! " << ma << endl;


    return 0;
}


