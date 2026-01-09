#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int  i = 1 ; i < n ;i++){
            int currp = prices[i] - mini; 
            profit = max(currp , profit);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};