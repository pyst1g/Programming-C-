// finish date: 2018/06/26
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;

class BinaryCalculator {
public:

    int minimumSteps(int a, int b) {
        int cnt;
        if (a == b) return 0;
        else if (a < b) {
            cnt = (b - a + 2) / 3;
            a += cnt * 3;
            if (a - b == 1) {
                cnt += 3;
            } else if (a - b == 2) {
                cnt += 1;
            }
        } else {
            cnt = (a - b + 1) / 2;
            b += cnt * 2;
            if (b - a == 1) {
                cnt += 2;
            }
        }
        return cnt;
    }

};







