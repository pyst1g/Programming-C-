// finish date: 2018/01/25
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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 500000000


/*　かなり汚いコードになってしまった。いつかきれいなコードに直したい　*/

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int suger_goal;
    int maxSW = -1, maxS = -1;
    rep(i, 31) {
        int j = 0;
        if (i == 0) j = 1;
        while (100*(A * i + B * j) <= F) {
            suger_goal = (A * i + B * j) * E;
            rep(k, 31) {
                int l = 0;
                while (C * k + D * l <= suger_goal) {
                    if (maxSW == -1 || (double) (100 * (C * k + D * l)) / ((A * i + B * j) * 100 + C * k + D * l) >
                                       (double) (100 * maxS) / maxSW) {
                        if ((A * i + B * j) * 100 + C * k + D * l <= F) {
                            maxSW = (A * i + B * j) * 100 + C * k + D * l;
                            maxS = C * k + D * l;
                        }
                    }
                    l++;
                }
            }
            j++;
        }
    }
    cout << maxSW << " " << maxS << endl;

    return 0;
}

