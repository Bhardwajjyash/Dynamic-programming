#include<bits/stdc++.h>
using namespace std;
int main()

class Solution {
private:
    int findrob(vector<int>& vec) {
        int n = vec.size();
        int prev = vec[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = vec[i];
            if (i > 1) {
                take += prev2;
            }
            int nottake = 0 + prev;
            int curri = max(take, nottake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> one, two;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                one.push_back(nums[i]);
            if (i != n - 1)
                two.push_back(nums[i]);
        }
        return max(findrob(one), findrob(two));
    }
};