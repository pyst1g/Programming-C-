// finish date: 2018/03/04

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
    int N;
    cin >> N;
    map<char, int> mp;
    string s;
    rep(i, N) {
        cin >> s;
        mp[s[0]]++;
    }
    vc vChar={'M','A','R','C','H'};
    ll ans = 0;
    rep(i,5){
        FOR(j,i+1,5){
            FOR(k,j+1,5){
                ans+=(ll)mp[vChar[i]]*(ll)mp[vChar[j]]*(ll)mp[vChar[k]];
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}



