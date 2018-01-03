// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

class FriendScore {
public:
    static int highestScore(vector<string> friends) {
        vector<vector<int>> two_fr_num(friends.size(), vector<int>(friends[0].length(), 0));
        rep(i, friends.size()) {
            rep(j, friends[i].size()) {
                if (friends[i][j] == 'Y' && friends[j][i] == 'Y') {
                    two_fr_num[i][j] = two_fr_num[j][i] = 1;
                    rep(k, friends[j].length()) {
                        if(friends[j][k] == 'Y' && friends[k][j] == 'Y' && i!=k){
                            two_fr_num[i][k] = two_fr_num[k][i] = 1;
                        }
                    }
                }
            }
        }

        int ma = 0;
        int temp;
        rep(i, two_fr_num.size()) {
            temp = 0;
            rep(j, two_fr_num[i].size()) {
                temp += two_fr_num[i][j];
            }
            ma = max(ma, temp);
        }
        return ma;
    }
};

