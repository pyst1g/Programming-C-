// finish date: 2018/01/28
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
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

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


int main() {
    int N;
    cin >> N;
    vvi A(2, vi(N));
    rep(i, 2) {
        rep(j, N) {
            cin >> A[i][j];
        }
    }
    rep(i,2){
        rep(j,N){
            if(i>0 && j>0) A[i][j] += max(A[i-1][j],A[i][j-1]);
            else if(i>0) A[i][j] += A[i-1][j];
            else if(j>0) A[i][j] += A[i][j-1];
        }
    }
    cout<<A[1][N-1]<<endl;


    return 0;
}

