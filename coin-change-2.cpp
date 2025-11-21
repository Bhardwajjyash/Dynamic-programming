#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long double> prev(amount+1, 0), curr(amount+1, 0);

        for (int t = 0; t <= amount; t++) {
            prev[t] = (t % coins[0] == 0);
        }

        for (int i = 1; i < n; i++) {
            curr.assign(amount + 1, 0);

            for (int target = 0; target <= amount; target++) {
                long double nottake = prev[target];
                long double take = 0;

                if (coins[i] <= target) {
                    take = curr[target - coins[i]];
                }

                curr[target] = take + nottake;
            }

            prev = curr;
        }

        return (long long)prev[amount];  
    }
};
