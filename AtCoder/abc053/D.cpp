// finish date: 2018/01/31
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
    map<int, int> count;
    int A;
    rep(i, N) {
        cin >> A;
        count[A]++;
    }
    int hasuu = 0;
    for (auto itr:count) {
        if (itr.second % 2 == 0) hasuu++;
    }
    int ans = count.size();
    ans -= hasuu % 2;
    cout << ans << endl;

    return 0;
}

