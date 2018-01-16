// finish date: 2018/01/11
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long


class TwoDiagonals {
public:
    bool isExist(char c, string str) {
        rep(i, str.length()) {
            if (c == str[i]) return true;
        }
        return false;
    }

    int fact(int n) {
        int ans = 1;
        FOR(i, 1, n + 1) {
            ans *= i;
        }
        return ans;
    }

    int maxPoints(vector<int> x, vector<int> y) {
        int N = x.size();
        map<int, int> diag1;
        map<int, int> diag2;
        int maVal1 = 0;
        int maVal2 = 0;
        vector<int> v1;
        vector<int> v2;
        rep(i, N) {
            diag1[x[i] - y[i]]++;
            diag2[x[i] + y[i]]++;
            if (diag1[x[i] - y[i]] > maVal1) {
                maVal1 = diag1[x[i] - y[i]];
                v1.clear();
                v1.shrink_to_fit();
                v1.emplace_back(x[i] - y[i]);
            } else if (diag1[x[i] - y[i]] == maVal1) {
                v1.emplace_back(x[i] - y[i]);
            }

            if (diag2[x[i] + y[i]] > maVal2) {
                maVal2 = diag2[x[i] + y[i]];
                v2.clear();
                v2.shrink_to_fit();
                v2.emplace_back(x[i] + y[i]);
            } else if (diag2[x[i] + y[i]] == maVal2) {
                v2.emplace_back(x[i] + y[i]);
            }
        }
        int a, b;
        rep(i, v1.size()) {
            rep(j, v2.size()) {
                a = v2[j] + v1[i];
                b = v2[j] - v1[i];
                if (a % 2 == 1) return maVal1 + maVal2;
                else {
                    rep(i, x.size()) {
                        if (x[i] == a / 2 && y[i] == (b / 2)) break;
                        if (i == x.size() - 1) return maVal1 + maVal2;
                    }
                }
            }
        }
        return maVal1 + maVal2 - 1;
    }

};
