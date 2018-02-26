// finish date: 2018/01/17
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    int ma = max(E+D+A,E+B+C);
    cout<<ma<<endl;


    return 0;
}
