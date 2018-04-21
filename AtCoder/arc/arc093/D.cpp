// finish date: 2018/03/25

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
    int A, B;
    cin >> A >> B;
    vvc ans;
    if (A > B) {
        ans = vvc(100, vc(100, '#'));
        B--;
    } else {
        ans = vvc(100, vc(100, '.'));
        A--;
    }
    int c = 0;
    int posy = 1, posx = 1;
    while (c != min(A, B)) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                ans[posy + i][posx + j] = (A > B) ? '.' : '#';
            }
        }
        posx += 4;
        if (posx + 1 >= 100) {
            posx = 1;
            posy += 4;
        }
        c++;
    }
    posy = 99;
    posx = 99;
    while (c < max(A, B)) {
        ans[posy][posx] = (A > B) ? '.' : '#';
        posx -= 2;
        if (posx < 0) {
            posy -= 2;
            posx = 99;
        }
        c++;
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100) {
        rep(j, 100) {
            cout << ans[i][j];
        }
        cout << endl;
    }


    return 0;
}