// finish date: 2018/05/05
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
    int H, W;
    cin >> H >> W;
    vs s(H);
    rep(i, H) cin >> s[i];
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '.') continue;
            for (int x = -1; x <= 1; x += 2) {
                if (0 <= j + x && j + x < W && s[i][j+x] == '#') goto outer;
            }
            for (int y = -1; y <= 1; y += 2) {
                if (0 <= i + y && i + y < H && s[i+y][j] == '#') goto outer;
            }
            cout<<"No"<<endl;
            return 0;
            outer:;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}