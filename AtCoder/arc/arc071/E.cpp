// finish date: 2018/04/24

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll double
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
    string S, T;
    cin >> S >> T;
    vi ruisekiS(S.length(), 0);
    vi ruisekiT(T.length(), 0);
    rep(i, S.length()) {
        if (S[i] == 'A') ruisekiS[i]++;
        else ruisekiS[i] += 2;
        if (i != 0) {
            ruisekiS[i] += ruisekiS[i - 1];
        }
    }
    rep(i, T.length()) {
        if (T[i] == 'A') ruisekiT[i]++;
        else ruisekiT[i] += 2;
        if (i != 0) {
            ruisekiT[i] += ruisekiT[i - 1];
        }
    }
    int q;
    cin >> q;
    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int valS = (a != 0) ? ruisekiS[b] - ruisekiS[a - 1] : ruisekiS[b];
        int valT = (c != 0) ? ruisekiT[d] - ruisekiT[c - 1] : ruisekiT[d];

        if ((valT - valS) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}