// finish date: 2018/12/18

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>>
        vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    //入力と変数宣言
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    int ans = 0;

    //値の出現回数をmapにカウント
    map<int, int> mp;
    rep(i, N) mp[A[i]]++;
    for (auto e = mp.rbegin(); e != mp.rend(); e++) {
        //cout << e->first << " " << e->second << endl; //確認
        while (e->second > 0) {
            if (log2(e->first) == (int) log2(e->first)) {
                //見てる値が2^nの場合
                if (e->second >= 2) {
                    e->second -= 2;
                    ans++;
                } else break;
            } else {
                //見てる値が2^n以外の場合
                int pow2t = 1 << (int) ceil(log2(e->first));
                if (mp[pow2t - e->first] > 0) {
                    e->second--;
                    mp[pow2t - e->first]--;
                    ans++;
                }else break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

