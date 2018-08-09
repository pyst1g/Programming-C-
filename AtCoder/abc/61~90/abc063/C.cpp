// finish date: 2018/01/22
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
    int N;
    cin >> N;
    vector<int> s(N);
    int sum = 0;
    bool flag = false;
    rep(i, N) {
        cin >> s[i];
        if(s[i]%10!=0) flag = true;
        sum += s[i];
    }
    if(!flag){
        cout<<0<<endl;
        return 0;
    }
    sort(s.begin(),s.end());
    if (sum % 10 == 0) {
        rep(i, N) {
            if (s[i] % 10 != 0) {
                sum -= s[i];
                break;
            }
        }
    }
    cout << sum << endl;

    return 0;
}

