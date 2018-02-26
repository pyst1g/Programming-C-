// finish date: 2018/02/24

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
    int N, L;
    cin >> N >> L;
    int a, b;
    int checkpoint = 0;
    rep(i, N) {
        cin >> a;
        if (i >= 1 && a + b >= L) checkpoint = i;
        b = a;
    }
    if (checkpoint == 0) cout << "Impossible" << endl;
    else {
        cout<<"Possible"<<endl;
        for (int i = 1; i < checkpoint; i++) cout << i << endl;
        for (int i = N - 1; i >= checkpoint; i--) cout << i << endl;
    }

    return 0;
}



