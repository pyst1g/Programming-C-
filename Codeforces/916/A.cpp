// finish date: 2018/01/19
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
    int x;
    string hh, mm;
    cin >> x >> hh >> mm;
    int time = stoi(hh)*60+stoi(mm);
    int h,m;
    int count = 0;
    while(true){
        h = time/60;
        m = time%60;
        if(h/10==7||h%10==7||m/10==7||m%10==7){
            cout << count<<endl;
            break;
        }
        count++;
        time-=x;
        if(time<0)time+=60*24;
    }
    return 0;
}
