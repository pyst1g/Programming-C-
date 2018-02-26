// finish date: 2018/01/20
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


int main() {
    int x,y;
    cin>>x>>y;
    map<int,int> mp;
    mp[1]=0;
    mp[2]=3;
    mp[3]=0;
    mp[4]=2;
    mp[5]=0;
    mp[6]=2;
    mp[7]=0;
    mp[8]=0;
    mp[9]=2;
    mp[10]=0;
    mp[11]=2;
    mp[12]=0;
    if(mp[x]==mp[y]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
