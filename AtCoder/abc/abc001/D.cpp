// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

vector<string> time_cout(int s_time, int e_time) {
    //if (s_time % 5 != 0) s_time = (int) (s_time / 5) * 5;
    //if (e_time % 5 != 0) e_time = (int) (e_time / 5) * 5 + 5;
    s_time = s_time / 60 * 100 + (s_time % 60);
    e_time = e_time / 60 * 100 + (e_time % 60);
    string str_s = to_string(s_time);
    string str_e = to_string(e_time);
    while (str_s.length() < 4) str_s = "0" + str_s;
    while (str_e.length() < 4) str_e = "0" + str_e;
    return vector<string> {str_s, str_e};
}

int main() {
    int N;
    string s;
    cin >> N;
    vector<int> S(N);
    vector<int> E(N);
    vector<bool> B(24 * 60 + 1, false); // 24時間を5分区切りにしたvector
    vector<vector<string>> output;
    rep(i, N) {
        cin >> s;
        S[i] = stoi(s.substr(0, 4));
        E[i] = stoi(s.substr(5, 4));
    }
    /*
    rep(i, S.size()) {
        if (S[i] % 5 != 0) S[i] = 5 * (int) (S[i] / 5);
        if (E[i] % 5 != 0) E[i] = 5 * (int) (E[i] / 5) + 5;
    }
    */
    int kuriage;
    rep(i, S.size()) {
        kuriage = (E[i] % 5 == 0) ? 0 : 5 - E[i] % 5;
        FOR(j, (int) ((S[i] / 100 * 60 + S[i] % 100) / 5) * 5, (E[i] / 100 * 60 + E[i] % 100) + kuriage + 1) {
            B[j] = true;
        }
    }
    int s_time = 0;
    int e_time = 0;
    FOR(i, 1, B.size()) {
        if (i == B.size() - 1) {
            if (!(B[i] || B[i - 1])) break;
            else {
                if (B[i] && B[i - 1]) e_time = i;
                else if (B[i]) s_time = e_time = i;
            }
            output.push_back(time_cout(s_time, e_time));
        } else if (B[i]) {
            e_time = i;
            if (!B[i - 1]) s_time = i;
        } else {
            if (B[i - 1]) {
                output.push_back(time_cout(s_time, e_time));
            }
        }
    }
    string out1 = output[0][0];
    string out2 = output[0][1];
    rep(i, output.size()) {
        if (i == output.size() - 1) cout << out1 << "-" << out2;
        else if (output[i][1] != output[i + 1][0]) {
            cout << out1 << "-" << out2;
            out1 = output[i + 1][0];
            out2 = output[i + 1][1];
        } else {
            out2 = output[i + 1][1];
            continue;
        }
        cout << endl;
    }
    return 0;
}
