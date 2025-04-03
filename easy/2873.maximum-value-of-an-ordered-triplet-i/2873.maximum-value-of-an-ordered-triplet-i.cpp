/*
 * @lc app=leetcode id=2873 lang=cpp
 *
 * [2873] Maximum Value of an Ordered Triplet I
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int maximum = nums[0];
        int dif = 0;
        long long ans = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            maximum = max(maximum, nums[i - 2]);
            dif = max(dif, maximum - nums[i - 1]);
            ans = max((1LL * dif * nums[i]), ans);
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.maximumTripletValue(nums) << endl;
    return 0;
}
// @lc code=end
