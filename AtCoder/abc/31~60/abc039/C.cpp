// finish date: 2018/01/18
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
    string out[] = {"Do","Do#","Re","Re#","Mi","Fa","Fa#","So","So#","La","La#","Si"};
    cin>>S;
    string kenban = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    rep(i,12){
        if(kenban.substr(i,20) == S){
            cout << out[i] <<endl;
            break;
        }
    }

    return 0;
}
