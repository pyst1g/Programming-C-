// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

int main() {
    double m;
    double VV = 0;
    cin >> m;
    m /= 1000;
    if (m < 0.1) VV = 0;
    else if (m <= 5) VV = m * 10;
    else if (6 <= m && m<= 30) VV = m + 50;
    else if (35 <= m && m<= 70) VV = (m - 30) / 5 + 80;
    else if (m > 70) VV = 89;
    if (VV / 10 < 1) cout << "0" << VV << endl;
    else cout << VV << endl;
}
