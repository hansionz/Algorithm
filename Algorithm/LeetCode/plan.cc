#include <vector>
#include <iostream>

using namespace std;
// Q:爬楼梯(LeetCode 70)
int climbStairs(int n){
    if(n == 1 || n == 2)
        return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
// 动态规划解法
// n > 2时,F(N) = F(N-1) + F(N-2)
int climbStairsDp(int n)
{
    // 定义边界条件
    int first = 1;
    int second = 2;
    int third = n;
    for(int i = 3; i <= n; i++){
        third = first + second;
        first = second;
        second = third;
    }
    return third;

}
// Q:打家劫舍(LeetCode 198)
// 动态规划解法: 
//              定义状态:i位置的状态为前i家获得的最大财富
//              边界状态:1位置的为num[1] 2位置的为num[1]和num[2]中的最大值
//              递推公式:i位置的为Max(dp[i - 2] + num[i], dp[i - 1])
int rob(vector<int>& nums){
    if(nums.size() == 0){
        return 0;
    }
    if(nums.size() == 1)
    {
        return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    // 初始状态
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++){
        dp[i] = max(dp[i -2] + nums[i], dp[i-1]);
    }
    return dp[dp.size() - 1];
}
// Q:连续子数组的最大和(LeetCode 53)
// 定义状态: 第i个位置的状态是前i个数最大连续子数组之和
// 边界状态: dp[0] = nums[0];dp[1] = max(dp[0] + nums[1], nums[1]);
// 递推公式: dp[i] = max(dp[i - 1] + nums[i], nums[i]);
int maxSubArray(vector<int>& nums){
    if(nums.size() == 0){
        return 0;
    }
    if(nums.size() == 1){
        return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    // 定义初始状态
    dp[0] = nums[0];
    int max_res = dp[0];
    for(int i = 1; i < nums.size(); i++){
        // 递推
        dp[i] = max(dp[i -1] + nums[i], nums[i]);
        if(dp[i] > max_res)
            max_res = dp[i];
    }
    return max_res;
}
// Q:找零钱（LeeCode 322）
// 定义状态: dp[i]代表金额为i的最优解
// 递推公式: coins[] = {1, 2, 5, 7, 10}
// dp[i] = min(dp[i-1], dp[i-2],dp[i-5],dp[i-7],dp[i-10]) + 1
// 初始状态: dp[1] = 1; dp[2] = 1; dp[5] = 1; dp[7] = 1; dp[10] = 1,其余初始状态为-1
int coinChange(vector<int>& coins, int amount){
    vector<int> dp;
    // 定义初始状态
    for(int i = 0; i <= amount; i++){
        dp.push_back(-1);
    }
    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++){
        for(int j = 0; j < coins.size(); j++){
            if(i  - coins[j] >= 0 && dp[i - coins[j]] != -1){
                if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1){
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }
    return dp[amount];
}
// Q:三角形（LeetCode 120）


// Q:最长上升子序列 (LeetCode 300)
// 定义状态: dp[i]代表以第i个元素结尾的最长上升子序列的长度,nums[i]一定是当前子序列中的最大值，因为在末尾
// 边界状态: 
#include <algorithm>
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
// 合并区间
class Solution {
public:
    static vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        if(intervals.size() == 1){
            return intervals;
        }
        vector<Interval> res;
        int i = 0;
        while(i < intervals.size()){
            int start = intervals[i].start;
            int end = intervals[i].end;
            int j = i + 1;
            while(j < intervals.size() && intervals[j].start <= end){
                if(end < intervals[j].end)
                    end = intervals[j].end;
                j++;
            }
            struct Interval merges(start, end);
            res.push_back(merges);
            i = j;
        }
        return res;
    }
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }
};
int main()
{
    Interval i1(1,3);
    Interval i2(2,4);
    vector<Interval> nums;
    nums.push_back(i1);
    nums.push_back(i2);
    vector<Interval> res = Solution::merge(nums); 
    for(int i = 0; i < res.size(); i++){
        cout << res[i].start << ":" << res[i].end << endl;
    }
    return 0;
}
