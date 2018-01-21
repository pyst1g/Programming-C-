// finish date: 2018/01/20
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
#define bigmod 1000000007
#define INF 500000000


int main() {
    string N;
    cin >> N;
    map<char, int> mp;
    mp[N[0]]++;
    mp[N[1]]++;
    mp[N[2]]++;
    mp[N[3]]++;
    if (mp[N[0]] >= 3 || mp[N[1]] >= 3) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
// finish date: 2018/01/20
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
#define bigmod 1000000007
#define INF 500000000


int main() {
    string S;
    cin >> S;
    if ((S[0] == S[1] && S[1] == S[2]) || (S[1] == S[2] && S[2] == S[3])) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
