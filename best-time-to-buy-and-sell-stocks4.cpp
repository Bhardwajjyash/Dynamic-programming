#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        vector<vector<int>> dp(n+1 , vector<int>(2 * k +1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int transNo = 2 * k - 1; transNo >= 0; transNo++) {

                if (transNo%2==0) {
                    dp[ind][transNo] =
                        max(-prices[ind] + dp[ind + 1][transNo + 1],
                            0 + dp[ind + 1][transNo]);
                } else {
                    dp[ind][transNo] =
                        max(prices[ind] + dp[ind + 1][transNo + 1],
                            0 + dp[ind + 1][transNo]);
                }
            }
        }
        return dp[0][0];
    }
};