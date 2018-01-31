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


class HalvingEasy {
public:

    int count(vector<int> S, int T) {
        int c = 0;

        rep(i, S.size()) {
            while (S[i] >= T) {
                if (S[i] == T) {
                    c++;
                    break;
                }
                S[i] /= 2;
            }
        }
        return c;
    }

};

