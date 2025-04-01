/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */

// @lc code=start
using namespace std;
#include <bits/stdc++.h>
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        priority_queue<int, vector<int>, greater<int>> small;
        priority_queue<int> big;
        // heat tail must choose
        // The remiains choose (k-1) pair  biggest or smallest
        for (int i = 0; i < weights.size() - 1; i++)
        {
            small.push(weights[i] + weights[i + 1]);
            big.push(weights[i] + weights[i + 1]);
        }
        long long ans = 0;
        for (int i = 1; i < k; i++)
        {
            int s = small.top();
            int b = big.top();
            small.pop();
            big.pop();
            ans += (b - s);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> weights = {1, 3, 5, 1};
    int k = 2;
    cout << s.putMarbles(weights, k) << endl;
    return 0;
}
// @lc code=end
