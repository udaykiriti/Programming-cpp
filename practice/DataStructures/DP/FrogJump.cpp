#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[2003][2003];
    int func(vector<int>&stones,int index,int prev)
    {
        if(index>=stones.size()-1) return true;
        if(prev==0) return false;

        if(dp[index][prev]!=-1) return dp[index][prev];
        bool flag=false;

        for(int i=index+1;i<stones.size();i++)
        {
            if(stones[i]-stones[index] == prev-1)
            {
                flag|=func(stones,i,prev-1);
            }
            if(stones[i]-stones[index] == prev)
            {
                flag|=func(stones,i,prev);
            }
            if(stones[i]-stones[index] == prev+1)
            {
                flag|=func(stones,i,prev+1);
            }

            if(stones[i]-stones[index]>prev+1)
            {
                break;
            }
        }

        return dp[index][prev]=flag;
    }

    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));

        if(stones[1]>=2)
            return false;

        return func(stones,1,1);
    }
};

int main() {
    Solution sol;
    vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << sol.canCross(stones1) << endl;
    vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};
    cout << sol.canCross(stones2) << endl;
    return 0;
}
