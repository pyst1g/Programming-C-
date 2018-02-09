// finish date: 2018/02/08

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

//最大公約数
ll gcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) {
        swap(a, b);
    }
    ll r = 1; //0以外であれば何でも
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ll n, k;
    cin >> n >> k;
//    if (n < k) {
//        cout << "No" << endl;
//        return 0;
//    }
    int i = 1;
    ll temp = 1;
    double check;
    while (i <= k) {
        check = (double)temp * (double)i/ (double)gcd(temp, (ll)i);
        temp = (ll) check;
        if(check != (double)temp){
            cout<<"No"<<endl;
            return 0;
        }
        i++;
    }
    n++;
    if(n%temp==0) cout<<"Yes"<<endl;
    else cout << "No" << endl;

    return 0;
}

