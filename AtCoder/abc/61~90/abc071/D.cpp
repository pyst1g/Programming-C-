// finish date: 2018/02/18

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

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;
    for (int i = N - 1; i >= 0; i--) {
        if (s1[i] != s2[i]) {
            s1.erase(i, 1);
            s2.erase(i, 1);
            N--;
            i--;
        }
    }
    int mode;
    int ans;
    if(s1[0]==s2[0]){
        ans = 3;
        mode = 0;
    }else{
        ans = 6;
        mode = 1;
    }
    FOR(i,1, N) {
        if (s1[i] == s2[i]) {
            ans = (mode == 0) ? mul(ans, 2) : mul(ans, 1);
            mode = 0;
        }else{
            ans = (mode==0)? mul(ans,2):mul(ans,3);
            mode = 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}


