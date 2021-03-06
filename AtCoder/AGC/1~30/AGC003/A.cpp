// finish date: 2018/02/24

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
    string S;
    cin>>S;
    map<char,int> mp;
    rep(i,S.length()) mp[S[i]]++;
    bool con1 = (mp['E']*mp['W']==0)&&(mp['E']!=0||mp['W']!=0);
    bool con2 = (mp['N']*mp['S']==0)&&(mp['N']!=0||mp['S']!=0);
    if(con1||con2) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}



