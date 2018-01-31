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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 500000000


class HandsShaking{
public:
    ll countPerfect(int n) {
        if (n == 0) return 0;
        vl hands = vl(51, 0);
        hands[0] = 1;
        for (int people = 2; people <= n; people += 2) {
            rep(i, people - 1) {
                if (i % 2 == 0) {
                    hands[people] += hands[i] * hands[people - i - 2];
                }
            }
        }
        return hands[n];
    }
};

