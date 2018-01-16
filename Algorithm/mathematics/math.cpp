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
#define bigmod 1000000007
#define INF 500000000

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int nCk(int n, int k) {
    if (k == 0) return 1;
    int ans = 1;
    FOR(i, 1, k + 1) {
        ans *= n;
        n--;
        ans /= i;
    }
    return ans;
}

int gcd(int a, int b){
    if(a< 0) a = -a;
    if(b < 0) b = -b;
    if(a < b){
        swap(a,b);
    }
    int r = 1; //0以外であれば何でも
    while(r != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}