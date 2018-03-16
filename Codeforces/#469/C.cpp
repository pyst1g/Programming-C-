// finish date: 2018/03/09

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
    string s;
    cin >> s;
    if (s == "") {
        cout << -1 << endl;
        return 0;
    }
    map<int, int> mp0, mp1;
    int n = s.length();
    rep(i, n) {
        if (s[i] == '0') {
            mp0[i+1] = 1;
        } else {
            mp1[i+1] = 1;
        }
    }
    int flag;
    int tempIdx;
    vvi ans;
    while (!(mp0.empty() && mp1.empty())) {
        vi output;
        output.emplace_back(mp0.begin()->first);
        tempIdx = mp0.begin()->first;
        mp0.erase(mp0.begin()->first);
        flag = 1;
        while (true) {
            if (flag == 1) {
                if (mp1.empty()) break;
                auto e = mp1.upper_bound(tempIdx);
                if (e != mp1.end()) {
                    tempIdx = e->first;
                    output.emplace_back(tempIdx);
                    mp1.erase(e);
                } else {
                    break;
                }
                flag *= -1;
            } else {
                auto e = mp0.upper_bound(tempIdx);
                if (e != mp0.end()) {
                    tempIdx = e->first;
                    output.emplace_back(tempIdx);
                    mp0.erase(e);
                } else {
                    cout << -1 << endl;
                    return 0;
                }
                flag *= -1;
            }
        }
        ans.emplace_back(output);
    }
    cout<<ans.size()<<endl;
    for (vi out:ans) {
        cout << out.size() << " ";
        rep(i, out.size()) {
            cout << out[i] << " ";
        }
        cout << endl;
    }

    return 0;
}



