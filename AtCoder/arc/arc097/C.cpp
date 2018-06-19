// finish date: 2018/05/12
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
    string s;
    int K;
    cin >> s >> K;
    int count = 0;
    map<string, int> mp;
    for (char c = 'a'; c <= 'z'; c++) {
        vs strarray;
        rep(i, s.length()) {
            if (s[i] == c) strarray.push_back(s.substr(i));
        }
        sort(strarray.begin(), strarray.end());
        rep(i, strarray.size()) {
            rep(j, strarray[i].length()) {
                if (mp[strarray[i].substr(0, j + 1)] == 0) {
                    count++;
                    mp[strarray[i].substr(0, j + 1)]++;
                }
                if (count == K) {
                    cout << strarray[i].substr(0, j + 1) << endl;
                    return 0;
                }
            }
        }
    }


    return 0;
}