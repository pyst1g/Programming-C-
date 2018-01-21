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

vector<vector<int>> sv;
vector<ll> salary;

ll dfs(int men) {
    if (salary[men] != -1) return salary[men];
    if (sv[men].empty()) {
        salary[men] = 1;
        return salary[men];
    }
    salary[men] = 0;
    rep(i, sv[men].size()) {
        salary[men] += dfs(sv[men][i]);
    }
    return salary[men];

}


ll totalSalary(vector<string> relations) {
    int N = relations.size();
    sv = vector<vector<int>>(N, vector<int>());
    salary = vector<ll>(N, -1);
    rep(i, N) {
        rep(j, N) {
            if (relations[i][j] == 'Y') {
                sv[i].push_back(j);
            }
        }
    }
    ll sum = 0;
    rep(i, N) dfs(i);
    rep(i, N) sum += salary[i];
    return sum;
}


int main() {
    int N,K;
    cin>>N>>K;
    int in;
    map<int,int> mp;
    rep(i,K){
        cin>>in;
        mp[in] = 0;
    }
    vector<int> ans;
    int checker;
    FOR(i,N,100000){
        checker = i;
        while(checker!=0){
            if(mp.count(checker%10)==0){
                checker/=10;
            }else{
                break;
            }
        }
        if(checker==0){
            cout << i<<endl;
            return 0;
        }
    }


    return 0;
}
