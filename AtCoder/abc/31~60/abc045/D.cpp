// finish date: 2018/02/02
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
    int H, W, N;
    cin >> H >> W >> N;
    int a, b;
    vl black(10, 0);
    black[0] = (ll) (H - 2) * (W - 2);
    map<pair<int, int>, ll> mp;
    rep(i, N) {
        cin >> a >> b;
        for (int i = -2; i <= 0; i++) {
            for (int j = -2; j <= 0; j++) {
                if ((0 < a + i && a + i <= H - 2) && (0 < b + j && b + j <= W - 2)) {
                    mp[{a + i, b + j}]++;
                }
            }
        }
    }
    for (auto entry:mp) black[entry.second]++;

    black[0] -= mp.size();
    rep(i, 10) cout << black[i] << endl;


    return 0;
}

