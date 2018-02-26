// finish date: 2018/02/20
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>5
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 500000000


class  IntervalIntersections{
public:

    int minLength(int x1, int y1, int x2, int y2){
        if(y1<=x2) return x2-y1;
        else if(y2<=x1) return x1-y2;
        else return 0;
    }




};

