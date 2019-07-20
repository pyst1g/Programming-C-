// finish date: 2018/02/26

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
    int A, B, C;
    cin >> A >> B >> C;
    if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ma = max({A, B, C});
    if(ma == A){
        cout<<(ll)B*C<<endl;
    }else if(ma ==B){
        cout<<(ll)C*A<<endl;
    }else {
        cout<<(ll)A*B<<endl;
    }

    return 0;


}



