#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);
        for (int k = 0; k < n; k++) {
            front[k] = triangle[n - 1][k];
        }
        vector<int> curr(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + front[j];
                int daigonal = triangle[i][j] + front[j + 1];
                curr[j] = min(down, daigonal);
            }
            front = curr;
        }
        return front[0];
    }
};