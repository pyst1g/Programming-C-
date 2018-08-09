// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)


int main() {
    string W;
    string ans="";
    cin >> W;
    rep(i,W.length()){
        if(W[i]!='a'&&W[i]!='i'&&W[i]!='u'&&W[i]!='e'&&W[i]!='o'){
            ans+=W[i];
        }
    }
    cout << ans << endl;
}
