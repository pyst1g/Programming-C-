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


class MakeTwoConsecutive {
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

    string solve(string S) {
        if(S.length()<=2) return "Impossible";
        rep(i,(int)S.length()-2) if(S[i] == S[i+2]) return "Possible";
        rep(i, (int) S.length() - 1) if (S[i] == S[i + 1]) return "Possible";
        return "Impossible";
    }


};