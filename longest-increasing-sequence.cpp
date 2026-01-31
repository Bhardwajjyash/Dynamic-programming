#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int func(int n, int ind, int prev_ind, vector<int>& nums,
             vector<vector<int>> &dp) {
        if (ind == n)
            return 0;
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        int length = 0 + func(n, ind + 1, prev_ind, nums, dp);//nottake
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {    //take
            length = max(length, 1 + func(n, ind + 1, ind, nums, dp));
        }
        return dp[ind][prev_ind+1] = length;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(n, 0, -1, nums, dp);
    }
};