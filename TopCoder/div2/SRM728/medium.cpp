// finish date: 2018/01/26
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
#define vb vector<bool>5
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 500000000
#define modulo 998244353


class IncreasingSequencesEasy {
public:
    int add(int a, int b) {
        return (int) (((ll) (a % modulo) + (b % modulo)) % modulo);
    }


    int count(vector<int> L, vector<int> R) {
        if(L.size()==1) return R[0]-L[0]+1;
        vvi DP(L.size(), vi(10001, 0));
        FOR(i, 1, 10001) {
            if (L[0] <= i && i <= R[0]) {
                DP[0][i] = add(DP[0][i], DP[0][i - 1] + 1);
            } else {
                DP[0][i] = DP[0][i - 1];
            }
        }
        FOR(i, 1, L.size()) {
            FOR(j, 1, 10001) {
                if (L[i] <= j && j <= R[i]) {
                    if (i != L.size() - 1) DP[i][j] = add(DP[i][j], DP[i][j - 1]);
                    DP[i][j] = add(DP[i][j], DP[i - 1][j - 1]);
                } else {
                    DP[i][j] = DP[i][j - 1];
                }
            }
        }
        int sum = 0;
        FOR(i, L[L.size() - 1], R[R.size() - 1] + 1) {

            sum = add(sum, DP[DP.size() - 1][i]);
        }
        return sum;
    }

};

