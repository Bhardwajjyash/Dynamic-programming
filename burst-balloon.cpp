#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 2; i >= 1; i--) {
            for (int j = 1; j <= n - 2; j++) {
                if (i > j)
                    continue;
                int maxi = INT_MIN;
                for (int ind = i; ind <= j; ind++) {
                    int coins = nums[i - 1] * nums[ind] * nums[j + 1] +
                                dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};