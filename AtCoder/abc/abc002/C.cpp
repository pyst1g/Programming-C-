// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)


int main() {
    int xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    xb -= xa;
    yb -= ya;
    xc -= xa;
    yc -= ya;
    xa = 0;
    ya = 0;
    double ans = abs(xb*yc-xc*yb)/2.0;
    printf("%.1f\n",ans);

}
