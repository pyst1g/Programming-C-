// finish date: 2018/02/18

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
    vvi c(3, vi(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }
    bool con1, con2, con3;

    FOR(i, 1, 101) {
        FOR(j, 1, 101) {
            FOR(k, 1, 101) {
                con1 = (c[0][0]-i)==(c[1][0]-j)&&(c[1][0]-j)==(c[2][0]-k);
                con2 =  (c[0][1]-i)==(c[1][1]-j)&&(c[1][1]-j)==(c[2][1]-k);
                con3 =  (c[0][2]-i)==(c[1][2]-j)&&(c[1][2]-j)==(c[2][2]-k);
                if(con1&&con2&&con3){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;

    return 0;
}


