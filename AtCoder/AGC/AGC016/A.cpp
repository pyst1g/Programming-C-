// finish date: 2018/07/23
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, s.length()) mp[s[i]]++;
    int ans = INF;
    for (auto e :mp) {
        char c = e.first;
        rep(i, s.length()) {
            if (s[i] != c) break;
            if(i == s.length()-1){
                cout<<0<<endl;
                return 0;
            }
        }
        int k = 1;
        string prev = s;
        string temp = "";
        int cnt = 0;
        while (true) {
            cnt++;
            temp = "";
            rep(i, prev.length() - 1) {
                if (prev[i] == c || prev[i + 1] == c) {
                    temp += c;
                } else {
                    temp += prev[i];
                }
            }
            prev = temp;
            rep(i, temp.length()) {
                if (temp[i] != c) break;
                if (i == temp.length() - 1) {
                    ans = min(ans, cnt);
                    goto outer;
                }
            }
        }
        outer:;
    }
    cout << ans << endl;


    return 0;
}

