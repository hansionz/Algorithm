#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

// Q:求子集1 （LeetCode78）
// 方法一: 回溯法,有和没有该子集的都去尝试一下
// eg: [1,2,3] 当存在[1]时，去递归[2,3]的情况,当不存在[1]时，递归[2,3]的情况
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item; // 产生各个子集的数组
        res.push_back(item);
        generate(0, nums, item, res);
        return res;
    }
private:
    void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>& res){
        if(i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        res.push_back(item);
        generate(i+1, nums, item, res);
        item.pop_back();
        generate(i+1,nums,item, res);
    }
};
// 方法二: 位运算
class Solution2{
public:
    vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    int all_set = 1 << nums.size(); // 记录所以可能出现集合的个数 nums.size = 3时 all_set = 8
    for(int i = 0; i < all_set; i++){
        vector<int> item;
        for(int j = 0; j < nums.size(); j++){
            if(i & (1 << j)){
                item.push_back(nums[j]);
            }
        }
        res.push_back(item);
    }
        return res;
    }
};

// Q: 求子集2,所给集合中有重复的元素 （LeetCode 90）
class Solution3 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        res.push_back(item);
        generate(0,  nums, res, item, res_set);
        return res;
    }
private:
    void generate(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& item, set<vector<int>>& res_set){
        if(i > nums.size()){
            return;
        }
        item.push_back(nums[i]);
        if(res_set.find(item) == res_set.end()){
            res.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, res, item, res_set);
        item.pop_back();
        generate(i+1, nums, res, item, res_set);
    }
};
// Q:组合数之和 (LeetCode 40)

int main()
{
    Solution3 so3;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    vector<vector<int> > res = so3.subsetsWithDup(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
