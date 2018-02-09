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


int main() {
    int x, y;
    cin >> x >> y;
    if(y==0){
        cout<<"No"<<endl;
        return 0;
    }
    if(y==1){
        if(x==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }

    x -= y-1;
    if (x >= 0 && x % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}


