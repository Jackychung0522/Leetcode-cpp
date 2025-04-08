/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] Minimum Number of Operations to Make Elements in Array Distinct
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int total = nums.size();
        int big = 0;
        unordered_map<int, int> record;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            record[nums[i]]++;
            if (record[nums[i]] == 2)
            {
                big++;
            }
        }
        int index = 0;

        while (total >= 3 && big != 0)
        {
            record[nums[index]]--;
            if (record[nums[index]] == 1)
            {
                big--;
            }
            index++;
            record[nums[index]]--;
            if (record[nums[index]] == 1)
            {
                big--;
            }
            index++;
            record[nums[index]]--;
            if (record[nums[index]] == 1)
            {
                big--;
            }
            index++;
            total = total - 3;
            ans++;
        }
        if (total < 3 && big > 0)
        {
            ans += 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.minimumOperations(nums) << endl; // Output: 0
    nums = {1, 2, 2, 3, 4};
    cout << s.minimumOperations(nums) << endl; // Output: 1
    return 0;
}
// @lc code=end
