// finish date: 2019/07/21

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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
    int N;
    ll K;
    cin >> N >> K;
    vi A(N);
    map<int, vi> mp;
    rep(i, N) {
        cin >> A[i];
        mp[A[i]].emplace_back(i);
    }
    int cnt = 0;
    int idx = 0;
    do {
        auto Iter = upper_bound(mp[A[idx]].begin(), mp[A[idx]].end(), idx);
        if (Iter == mp[A[idx]].end()) {
            cnt++;
            idx = mp[A[idx]][0];
        } else {
            idx = *Iter;
        }
        idx++;
        idx = idx % N;
    } while (idx != 0);
    cnt++;

    ll res = K % (ll) cnt;
    if (res == 0) return 0;
    cnt = 0;
    while (cnt != res - 1) {
        auto Iter = upper_bound(mp[A[idx]].begin(), mp[A[idx]].end(), idx);
        if (Iter == mp[A[idx]].end()) {
            cnt++;
            idx = mp[A[idx]][0];
        } else {
            idx = *Iter;
        }
        idx++;
//        idx = idx % N;
    }

    vi s(N, INF);
    map<int, int> idx_mp;
    int temp = 0;
    FOR(a, idx, N) idx_mp[A[a]] = INF;
    FOR(a, idx, N) {
        if (temp <= idx_mp[A[a]]) {
            s[temp] = A[a];
            idx_mp[A[a]] = temp;
            temp++;
        } else {
            int place = idx_mp[A[a]];
            FOR(i, idx_mp[A[a]], temp) idx_mp[s[i]] = INF;
            temp = place;

//            idx_mp.erase(A[a]);
        }
    }
    rep(i, temp) {
        cout << s[i] << " ";
    }
    cout << endl;


    return 0;
}
