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

class CorporationSalary{
public:
    vector<vector<int>> sv;
    vector<ll> salary;

    ll calc(int men) {
        if (salary[men] != -1) return salary[men];
        if (sv[men].empty()) {
            salary[men] = 1;
            return salary[men];
        }
        salary[men] = 0;
        rep(i, sv[men].size()) {
            salary[men] += calc(sv[men][i]);
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
        rep(i, N) calc(i);
        rep(i, N) sum += salary[i];
        return sum;
    }
};
