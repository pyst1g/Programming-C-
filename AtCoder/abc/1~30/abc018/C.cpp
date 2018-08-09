// finish date: 2018/01/10
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

int main() {
    int R, C, K;
    cin >> R >> C >> K;
    int n;
    vector<string> s(R);
    rep(i, R) cin >> s[i];
    vector<vector<int>> x(R, vector<int>(C, 0));
    vector<vector<int>> y(R, vector<int>(C, 0));
    //if(R==1)
    rep(i, R) {
        rep(j, C) {
            rep(k, C) {
                if (!(0 <= j - k && j + k < C) || s[i][j + k] != 'o' || s[i][j - k] != 'o') {
                    x[i][j] = k;
                    break;
                }
                if (k == C - 1) x[i][j] = k + 1;
            }
            rep(k, R) {
                if (!(0 <= i - k && i + k < R) || s[i + k][j] != 'o' || s[i - k][j] != 'o') {
                    y[i][j] = k;
                    break;
                }
                if (k == R - 1) y[i][j] = k + 1;
            }
        }
    }
//    rep(i,R){
//        rep(j,C){
//            cout<<y[i][j]<<" ";
//        }cout <<endl;
//    }
    int count = 0;
    FOR(i, K - 1, (R - K + 1)) {
        FOR(j, K - 1, (C - K + 1)) {
            //if(0<=j-(K-1) && j+(K-1)<=C)
            rep(k, K) {
                if (y[i][j + k] < K - k || y[i][j - k] < K - k) break;
                else if (k == K - 1) count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}