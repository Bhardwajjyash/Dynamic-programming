#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> dp;
    bool isPallindrome(string s, int i, int j) {
        if (i == j)
            return true;
        if (i > j)
            return true;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }

    int solve(string s, int i, int j) {
        int mm = INT_MAX;
        int temp = 0;
        if (i >= j)
            return 0;
        if (isPallindrome(s, i, j) == true)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = 0 ;
        int right = 0;
        for (int k = i; k <= j - 1; k++) {
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else{
                left = solve(s, i, k);
                dp[i][k] = left; 
            }
            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }
            else{
                right = solve(s, k+1, j);
                dp[k+1][j] = right; 
            }
            temp = 1+left+right;
            if (temp < mm) {
                mm = temp;
            }
        }
        return dp[i][j] = mm;
    }

public:
    int minCut(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        int i = 0;
        int j = n - 1;
        return solve(s, i, j);
    }
};