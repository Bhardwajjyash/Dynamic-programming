#include<bits/stdc++.h>
using namespace std;

class Solution {
int f(int i ,vector<int>& arr,int k,vector<int> &dp ){
    int n = arr.size();
    if(i == n )return 0;
    if(dp[i] != -1) return dp[i] ;
    int len = 0;
    int maxi = INT_MIN;
    int maxans = INT_MIN;
    for(int ind = i ; ind < min(i+k,n); ind++){
        len++;
        maxi = max(maxi , arr[ind]);
        int sum = maxi * len + f(ind + 1, arr, k, dp);
        maxans = max(maxans,sum);
    } 
    return dp[i] = maxans;
}
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};