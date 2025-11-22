#include<bits/stdc++.h>
using namespace std;


// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        int rl = n+1;
        vector<vector<int>> dp(n,vector<int>(rl,0));
        for(int i = 0 ; i <= n; i++){
            dp[0][i] = i*price[0];
        }
        for(int i = 1 ; i < n ;i++){
            for(int N = 0;N<=n;N++){
                int nottake = 0 + dp[i-1][N];
                int take = -1e9;
                int rodlength = i+1;
                if(rodlength <= N){
                    take = price[i] + dp[i][N - rodlength];
                }
                dp[i][N] = max(take,nottake);
            }
        }
        return dp[n-1][n];
    }
};