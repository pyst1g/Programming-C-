// finish date: 2018/05/18
#include <bits/stdc++.h>


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


int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    vc seq(N, '?');
    char which[] = {'S', 'W'};

    rep(i, 2) {
        rep(j, 2) {
            seq = vc(N, '?');
            seq[0] = which[i];
            seq[1] = which[j];
            bool con = ((seq[0] == 'S' && ((seq[1] == 'S' && s[0] == 'o') || (seq[1] == 'W' && s[0] == 'x')))
                        ||
                        (seq[0] == 'W' && ((seq[1] == 'S' && s[0] == 'x') || (seq[1] == 'W' && s[0] == 'o'))));
            seq[N - 1] = (con) ? 'S' : 'W';;

            int seq_first = seq[0];
            int seq_last = seq[N - 1];

            FOR(k, 1, N) {
                con = ((seq[k] == 'S' && ((seq[k - 1] == 'S' && s[k] == 'o') || (seq[k - 1] == 'W' && s[k] == 'x')))
                       ||
                       (seq[k] == 'W' && ((seq[k - 1] == 'S' && s[k] == 'x') || (seq[k - 1] == 'W' && s[k] == 'o'))));
                seq[(k + 1) % N] = (con) ? 'S' : 'W';
            }
            if (seq[0] == seq_first && seq[N - 1] == seq_last) {
                rep(i, N) {
                    cout << seq[i];
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}