// finish date: 2018/01/23
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
#define bigmod 1000000007
#define INF 500000000

ll calc(ll N) {
    if (N == 0) return 0;
    ll n = N;
    vi ban = {1, 2, 3, 4, 4, 5, 6, 7, 8, 8}; //ban[i]=0~iまでで禁止されてない数の総数
    ll ans = 0;
    int val;

    bool is4or9 = false;
    string S = to_string(N);
    int i;
    for (i = 0; i < S.length(); i++) {
        if (S[i] == '4' || S[i] == '9') { ;
            is4or9 = true;
            break;
        }
    }

    i = max(0, (int) S.length() - (i + 1));

    n /= (ll) pow(10, i);
    while (n != 0) {
        val = (int) (n % 10);
        n /= 10;
        if (val == 0) {
            i++;
            continue;
        }else{
            if (!is4or9) ans++;
            is4or9=true; //2回目はない
        }
        //if (val != 4 && val != 9) ans++;
        ans += (ll) ban[val - 1] * (ll) pow((ll)ban[9], i); //ban[9]=8
        i++;
    }
    return N - ans + 1;
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << calc(B) - calc(A - 1) << endl;


    return 0;
}

