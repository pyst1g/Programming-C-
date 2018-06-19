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
    int N;
    cin >> N;
    vi a(N);
    int n = 0;
    int temp = 55555;
    while (n < N) {
        if (temp % 5 != 1) goto outer;
        FOR(i, 2, sqrt(temp + 1)) {
            if (temp % i == 0) goto outer;
        }
        a[n] = temp;
        n++;
        outer:;
        temp--;
    }
    rep(i, N) cout << a[i] << " ";
    cout << endl;

    return 0;
}