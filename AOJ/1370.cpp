// finish date: 2018/04/30

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

int search(string s, char c) {
    if (c < s[0]) return -1;
    if (s[s.length() - 1] < c) return s.length() - 1;
    int n = s.length();
    int l = 0;
    int r = n - 1;
    int m = (l + r) / 2;
    while (l <= r) {
        m = (l + r) / 2;
        if (s[m] == c) return m;
        else if (s[m] < c) {
            l = m + 1;
        } else {
            m--;
            r = m;
        }
    }
    return m;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int N = s1.length();
    int M = s2.length();
    map<string, int> mp1, mp2;
    rep(i, N) {
        string temp = "";
        FOR(j, i, N) {
            if (temp == "") temp += s1[j];
            else {
                int index = search(temp, s1[j]);
                if (index == -1) temp = s1[j] + temp;
                else if (index >= temp.length() - 1) temp += s1[j];
                else temp = temp.substr(0, index + 1) + s1[j] + temp.substr(index + 1);
            }
            mp1[temp]++;
        }
    }
    rep(i, M) {
        string temp = "";
        FOR(j, i, M) {
            if (temp == "") temp += s2[j];
            else {
                int index = search(temp, s2[j]);
                if (index == -1) temp = s2[j] + temp;
                else if (index >= temp.length() - 1) temp += s2[j];
                else temp = temp.substr(0, index + 1) + s2[j] + temp.substr(index + 1);
            }
            mp2[temp]++;
        }
    }
    int ma = 0;
    for (auto e:mp1) {
        if (mp2.count(e.first) != 0) ma = max(ma, (int) e.first.length());
    }
    cout << ma << endl;


    return 0;
}