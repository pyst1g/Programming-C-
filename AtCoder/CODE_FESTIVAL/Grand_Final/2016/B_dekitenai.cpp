// finish date: 2018/06/05
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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000

double solve(double x1, double y1, double x2, double y2, double x3, double y3) {
    double medX = (x2 + x3) / 2;
    double mexY = (y2 + y3) / 2;
    double len_teihen = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double d = sqrt(pow(x1 - medX, 2) + pow(y1 - mexY, 2));
    double x = 2 * d / (2 + 3 * len_teihen / d);
    return (d - x) / 3;

    double a = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    double b = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    double c = sqrt(pow(x3-x2,2)+pow(y3-y2,2));

}


int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double ma1 = solve(x1, y1, x2, y2, x3, y3);
    double ma2 = solve(x2, y2, x1, y1, x3, y3);
    double ma3 = solve(x3, y3, x2, y2, x1, y1);
    cout << max(ma1, max(ma2, ma3)) << endl;

    return 0;
}



