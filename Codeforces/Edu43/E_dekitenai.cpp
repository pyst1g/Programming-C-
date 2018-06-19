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


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vl hp(n), dmg(n);
    ll total = 0;
    rep(i, n) {
        cin >> hp[i] >> dmg[i];
        total += dmg[i];
    }
    if (b == 0) {
        cout << total << endl;
        return 0;
    }

    vl difA(n);
    ll maxdif = LONG_LONG_MIN;
    rep(i, n) {
        difA[i] = hp[i] * (1 << a) - dmg[i];
        maxdif = max(maxdif, difA[i]);
    }
    vl difB(n);
    rep(i, n) {
        difB[i] = hp[i] - dmg[i];
    }
    sort(difB.begin(), difB.end(), greater<ll>());
    ll tempmax = 0;
    ll temptotal = 0;
    ll last = 0;
    int index = 0;
    rep(i, b - 1) {
        index = i;
        last = difB[i];
        if (difB[i] < 0) break;
        temptotal += difB[i];
    }
    rep(i, n) {
        if (difA[i] < 0) break;
        if (difB[i] < last) {
            tempmax = max(tempmax, temptotal + difA[i]);
        } else if (difB[i] == last) {
            if (index < n && difB[index] == last) {
                tempmax = max(tempmax, temptotal + difA[i]);
            } else {
                if (index + 1 < n && difB[index + 1] > 0) tempmax = max(tempmax, temptotal + difB[index + 1]);
                else tempmax = max(tempmax, temptotal);
            }
        } else {
            if (index + 1 < n && difB[index + 1] > 0) tempmax = max(tempmax, temptotal + difB[index - 1]);
            else tempmax = max(tempmax, temptotal);
        }
    }

    if (tempmax > 0) cout << total + tempmax << endl;
    else cout << total << endl;

    return 0;
}