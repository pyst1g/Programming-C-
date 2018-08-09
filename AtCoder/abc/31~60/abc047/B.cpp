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
    int W, H, N;
    cin >> W >> H >> N;
    vector<vector<int>> v(H, vector<int>(W, 1));
    int x, y, a;
    int s, e;
    rep(i, N) {
        cin >> x >> y >> a;
        if (a == 1 || a == 2) {
            if (a == 1) {
                s = 0;
                e = x;
            } else {
                s = x;
                e = W;
            }
            rep(j, H) {
                FOR(k, s, e) {
                    v[j][k] = 0;
                }
            }
        } else {
            if (a == 3) {
                s = 0;
                e = y ;
            } else {
                s = y;
                e = H ;
            }
            FOR(j, s, e) {
                rep(k, W) {
                    v[j][k] = 0;
                }
            }
        }
//        rep(j,H){
//            rep(k,W){
//                cout << v[j][k];
//            }cout<<endl;
//        }
    }

    int sum = 0;
    rep(i, H) rep(j, W) sum += v[i][j];
    cout << sum << endl;

    return 0;
}