// finish date: 2018/01/09
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
    int txa, tya, txb, tyb, T, V, n;
    cin >> txa >> tya >> txb >> tyb >> T >> V >> n;
    int x, y;
    //double distance = sqrt(pow(txb-txa,2)+pow(tyb-tya,2));
    double dis1,dis2;
    rep(i, n) {
        cin >> x >> y;
        dis1=sqrt(pow(x-txa,2)+pow(y-tya,2));
        dis2=sqrt(pow(x-txb,2)+pow(y-tyb,2));
        if(dis1+dis2<=T*V){
            cout <<"YES"<<endl;
            return 0;
        }
    }
    cout <<"NO"<<endl;

    return 0;
}



