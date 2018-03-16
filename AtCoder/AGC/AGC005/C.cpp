// finish date: 2018/03/10

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

void minusMapSecond(map<int, int> &mp, int key) {
    mp[key]--;
    if (mp[key] == 0) mp.erase(key);
}

int main() {
    int N;
    cin >> N;
    int a;
    map<int, int> possibleNode;
    rep(i, N) {
        cin >> a;
        possibleNode[a]++;
    }
    int ma = possibleNode.rbegin()->first;
    minusMapSecond(possibleNode, ma);

    FOR(i, 1, ma + 1) {
        if (possibleNode.count(max(i, ma - i)) == 0) {
            cout << "Impossible" << endl;
            return 0;
        }
        minusMapSecond(possibleNode, max(i, ma - i));
    }
    if (possibleNode.empty()) {
        cout << "Possible" << endl;
        return 0;
    }
    bool con1 = (ma + 1) / 2 + 1 <= possibleNode.begin()->first;
    bool con2 = possibleNode.rbegin()->first <= ma;
    if (con1 && con2) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}