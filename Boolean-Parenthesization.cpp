#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
  #define ll long long int
class Solution {
     ll f(int i, int j, int istrue, string s,
         vector<vector<vector<ll>>>& dp) {
        if (i > j)
            return 0;
        if (i == j) {
            if (istrue) {
                return s[i] == 'T';
            } else
                return s[i] == 'F';
        }
        if (dp[i][j][istrue] != -1)
            return dp[i][j][istrue];
        ll ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2 ) {
            ll lt = f(i, ind - 1, 1, s, dp);
            ll lf = f(i, ind - 1, 0, s, dp);
            ll rt = f(ind + 1, j, 1, s, dp);
            ll rf = f(ind + 1, j, 0, s, dp);
            if (s[ind] == '&') {
                if (istrue) {
                    ways = (ways + (lt * rt));
                } else
                    ways = ways + lt * rf + lf * rt + lf * rf;
            } else if (s[ind] == '|') {
                if (istrue) {
                    ways = (ways + (lt * rt + lt * rf + lf * rt));
                } else
                    ways = ways + lf * rf;
            } else if (s[ind] == '^') {
                if (istrue) {
                    ways += lt * rf + lf * rt;
                } else {
                    ways += lt * rt + lf * rf;
                }
            }

        }
        return dp[i][j][istrue] = ways;
    }
    
  public:
    int countWays(string &s) {
          int n = s.size();
        vector<vector<vector<ll>>> dp(n, vector <
                                             vector<ll>>(n, vector<ll>(2, -1)));
        return f(0, n - 1, 1, s, dp);
        
    }
};