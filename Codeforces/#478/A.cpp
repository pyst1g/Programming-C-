// finish date: 2018/05/01

#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    vs S(n);
    map<string, int> mp;
    rep(i, n) {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
        string temp = "";
        rep(j, S[i].length()) {
            if (j == 0 || temp[temp.length() - 1] != S[i][j]) temp += S[i][j];
        }
        mp[temp]++;
    }
    cout << mp.size() << endl;


    return 0;
}