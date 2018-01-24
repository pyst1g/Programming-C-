// finish date: 2018/01/24
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
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
#define bigmod 1000000007
#define INF 500000000


int main() {
    int N, M;
    cin >> N >> M;
    int time = 1900 * M + (N - M) * 100;
    cout << time * (1 << M) << endl;


    return 0;
}

