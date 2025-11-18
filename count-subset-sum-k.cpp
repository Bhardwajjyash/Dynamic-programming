#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9+7;
        
        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        // Initialize dp[0][0]
        dp[0][0] = (arr[0] == 0 ? 2 : 1);

        // If arr[0] <= target and arr[0] != 0
        if (arr[0] != 0 && arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int nottake = dp[i-1][sum];
                int take = 0;
                if (arr[i] <= sum)
                    take = dp[i-1][sum - arr[i]];

                dp[i][sum] = (take + nottake) % mod;
            }
        }
        return dp[n-1][target];
    }
};
