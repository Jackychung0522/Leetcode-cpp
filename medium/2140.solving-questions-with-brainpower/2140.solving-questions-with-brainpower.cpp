/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            int nextIndex = i + brainpower + 1;

            long long solve = points;
            if (nextIndex < n)
            {
                solve += dp[nextIndex];
            }
            long long skip = dp[i + 1];
            dp[i] = max(solve, skip);
        }

        return dp[0];
    }
};
// @lc code=end
