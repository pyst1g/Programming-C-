// finish date: 2018/12/15

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

bool arrayAdd(vi &tempstr, int head, int tail, int m) {
    FOR(i, tail, head) {
        if (tempstr[i] + 1 <= m) {
            FOR(j, tail, head) {
                tempstr[j]++;
                if (tempstr[j] > m) tempstr[j] = 1;
                else return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    int ans = INT_MAX;
    N += 50;
    int m = N / 2, r = N + 1, l = 1;
    //int olm = m, olr = r, oll = l;
    while (l <= r) {
        vi tempstr(2 * N + 1, 1);
        int head = 2 * N + 1;//気を付けなはれ
        int tail = head - min(N, A[0]);
        bool flag = true;
        FOR(i, 1, N - 50) {
            if (A[i - 1] < A[i]) {
                tail--;
                tempstr[tail] = 1;
            } else if (A[i - 1] == A[i]) {
                flag = arrayAdd(tempstr, head, tail, m);
                if (!flag) break;
            } else {
                if (A[i] > N) continue;
                /*FOR(j, head - A[i], head) {
                    tempstr[j - (head - A[i])] = tempstr[head - A[i]];
                }
                head = A[i];*/
                tail = head - A[i];
                flag = arrayAdd(tempstr, head, tail, m);
                if (!flag) break;
            }
        }
        if (flag) {
            ans = min(ans, m);
            r = m - 1;
            m = (l + r) / 2;
        } else {
            l = m + 1;
            m = (l + r) / 2;
        }
        //  if (olm == m && olr == r && oll == l) break;
        //  olm = m, olr = r, oll = l;
    }
    cout << ans << endl;
    return 0;
}



