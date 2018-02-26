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


class  ExpectedMinimumPowerDiv2{
public:
//組み合わせ
    double nCk(double n, double k) {
        if (k == 0) return 1;
        double ans = 1;
        FOR(i, 1, k + 1) {
            ans *= n;
            n--;
            ans /= i;
        }
        return ans;
    }


    double findExp(int n, int x){
        if(n==1) return 2.0;
        if(n==x) return 2.0;
        double ans = 0;
        for(int i=1;i<=n-x+1;i++){
            ans += nCk(n-i,x-1) * pow(2,i);
            // cout<<i<<" "<<nCk(n-i,x-1)<<endl;
        }
        ans /= nCk(n,x);
        return ans;
    }


};

