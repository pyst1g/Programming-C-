// finish date: 2018/01/09
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <limits>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    if (K == 0 || K == 1) {
        cout << S << endl;
        return 0;
    }
    string sortS = S;
    sort(sortS.begin(), sortS.end());
    int count = 0;
    vector<int> isSwap(S.length(), 1);
    char minc = 'z' + 1;
    int min_index = -1;
    int min_swap = 2;

    rep(i, N) {
        minc = 'z' + 1;
        min_index = -1;
        min_swap = 2;
        if (S[i] != sortS[i]) {
            for (int j = S.length() - 1; j > i; j--) {
                if (S[j] <= minc && S[j] < S[i]) {
                    if (S[j] < minc || isSwap[j] < min_swap) {
                        if (count + isSwap[i] + isSwap[j] <= K) {
                            minc = S[j];
                            min_index = j;
                            min_swap = isSwap[j];
                        }
                    }
                }
            }
            if (min_index != -1) {
                count += isSwap[i];
                count += isSwap[min_index];
                swap(S[i], S[min_index]);
                isSwap[i] = 0;
                isSwap[min_index] = 0;
            }
        }
    }
    string s1 = "", s2 = "";
    int c1 = 0, c2 = 0;
    rep(i, N) {
        if (!isSwap[i]) {
            s1 += S[i];
            //c1++;
        } else {
            s2 += S[i];
            //c2++;
        }
    }
    string str = "";
    sort(s1.begin(), s1.end());
    rep(i, N) {
        if (!isSwap[i]) {
            str += s1[c1];
            c1++;
        }
        else {
            str += s2[c2];
            c2++;
        }
    }


    cout << str << endl;
}

