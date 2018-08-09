// finish date: 2018/02/03
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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000



int main() {
    string s;
    cin >> s;
    if(s.length()==2){
        if(s[0]==s[1]) cout<<1<<" "<<2<<endl;
        else cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    rep(i, s.length() - 2) {
        if (s[i] == s[i + 1] || s[i + 1] == s[i + 2] || s[i + 2] == s[i]) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}

