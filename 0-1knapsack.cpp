#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int w = wt[0] ; w<=W;w++){
            dp[0][w] = val[0];
        }
        for(int i = 1 ; i < n;i++){
            for(int w = 0; w <= W;w++){
                int nottake = 0 + dp[i-1][w];
                int take =  INT_MIN;
                if(wt[i] <= w){
                    take = val[i]+dp[i-1][w-wt[i]];
                }
                dp[i][w] = max(take,nottake);
            }
        }
        return dp[n-1][W];
    }
};