#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), curr(n, 0);
        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if (j - 1 >= 0)
                    ld += prev[j - 1];
                else
                    ld += 1e9;
                int rd = matrix[i][j];
                if (j + 1 < n)
                    rd += prev[j + 1];
                else
                    rd += 1e9;
                curr[j] = min(u, min(ld, rd));
            }
            prev = curr;
        }
        int mini = 1e9;
        for (int k = 0; k < n; k++) {
            mini = min(mini, prev[k]);
        }
        return mini;
    }
};