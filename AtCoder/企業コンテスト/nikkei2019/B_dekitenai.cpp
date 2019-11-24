// finish date: 2019/11/09

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
const int INF = 1000000007;
const long long INFll = 100000000000000000;


int main() {
    int N;
    cin >> N;
    vi A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<pii> ab;
    bool flag = true;
    rep(i, N) {
        if (A[i] <= B[i]) {
            ab.push_back(pii(A[i], B[i]));
            flag = false;
        }
    }
    if (flag) {
        cout << "No" << endl;
        return 0;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    map<int, int> posA, posB;
    rep(i, N) {
        posA[A[i]] = i;
        posB[B[i]] = i;
    }

    rep(i, N) {
        if (A[i] > B[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    vi can_slide(N, 0);
    can_slide[0] = 1;
    FOR(i, 1, N) {
        if (A[i] <= B[i - 1]) {
            can_slide[i] = 1;
        }
        can_slide[i] += can_slide[i - 1];
    }
    for (pii e: ab) {
        int a = e.first;
        int b = e.second;
        if (posA[a] <= posB[b]) {
            if (can_slide[posB[b]] - can_slide[posA[a]] == posB[b] - posA[a]) {
                cout << "Yes" << endl;
                return 0;
            }
        }else{
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout << "No" << endl;


    return 0;
}
