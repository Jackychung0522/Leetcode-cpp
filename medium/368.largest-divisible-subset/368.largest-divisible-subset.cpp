/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        int maxl = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxl = max(maxl, dp[i]);
        }
        vector<int> ans;
        int I;
        for (int i = dp.size() - 1; i >= 0; i--)
        {
            if (dp[i] == maxl)
            {
                ans.push_back(nums[i]);
                I = nums[i];
                maxl--;
                break;
            }
        }
        for (int i = dp.size() - 1; i >= 0; i--)
        {
            if (dp[i] == maxl)
            {
                if (I % nums[i] == 0)
                {
                    ans.push_back(nums[i]);
                    I = nums[i];
                    maxl--;
                    if (maxl == 0)
                    {
                        break;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
