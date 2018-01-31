// finish date: 2018/01/18
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
#define bigmod 1000000007
#define INF 500000000

class ColorfulBoxesAndBalls {
public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
        int ma = -INF;
        int sum;
        int minColor = min(numRed, numBlue);
        rep(i, minColor+1) {
            sum = 0;
            sum += i * onlyRed;
            sum += i * onlyBlue;
            sum += 2 * (minColor - i) * bothColors;
            ma = max(sum, ma);
        }
        if(numRed>numBlue) ma+=(numRed-numBlue)*onlyRed;
        else ma+=(numBlue-numRed)*onlyBlue;
        return ma;
    }

};
