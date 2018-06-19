// finish date: 2018/05/15
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

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}


int main() {
    int N;
    cin >> N;
    map<int, char> mp;
    rep(i, N) {
        int in;
        cin >> in;
        mp[in] = 'a';
    }
    rep(i, N) {
        int in;
        cin >> in;
        mp[in] = 'b';
    }
    int countA = 0, countB = 0;
    int ans = 1;
    for (auto e:mp) {
        if (e.second == 'a') {
            if (countB == 0) countA++;
            else {
                ans = mul(ans, countB);
                countB--;
            }
        } else {
            if (countA == 0) countB++;
            else {
                ans = mul(ans, countA);
                countA--;
            }
        }
    }
    cout << ans << endl;


    return 0;
}