#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 线段树是一颗平衡二叉搜索树(完全二叉树)
// 线段树的构造
void bulid_segment_tree(vector<int>& value, vector<int>& nums, int pos, int left, int right){
    if(left == right){
        value[pos] = nums[left];
        return;
    }
    int mid = (right - left) / 2 + left;
    bulid_segment_tree(value, nums, pos*2 + 1, left, mid);
    bulid_segment_tree(value, nums, pos*2 + 2, mid + 1, right);
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}
// 线段树的遍历
void print_segment_tree(vector<int>& value, int pos, int left, int right, int layer){
    for(int i = 0; i < layer; i++){
        cout << "-";
    }
    cout << "[" << left << "," << right << "] " << pos << ":" << value[pos] << endl;
    if(left == right){
        return;
    }
    int mid = left + (right - left) / 2;
    print_segment_tree(value, 2 * pos + 1, left, mid, layer + 1);
    print_segment_tree(value, 2 * pos + 2, mid + 1, right, layer + 1);
}
// 线段树的求和
int sum_range_segment_tree(vector<int>& value, int pos, int left, int right, int qleft, int qright){
    if(qleft > right || qright < left){// 没有交集
        return 0;
    }
    if(qleft <= left && qright >= right){
        return value[pos];
    }
    int mid = left + (right - left) / 2;
    return sum_range_segment_tree(value, 2 * pos + 1, left, mid, qleft,qright) + 
    sum_range_segment_tree(value, 2 * pos + 2, mid + 1, right, qleft, qright);
}
// 线段树的更新
void update_segment_tree(vector<int>& value, int pos, int left, int right, int index, int new_value){
    if(left == right){
        value[pos] = new_value;
        return;
    }
    int mid = left + (right - left) / 2;
    if(index <= mid){
        update_segment_tree(value, 2 * pos + 1, left, mid, index, new_value);
    }
    else{
        update_segment_tree(value, 2 * pos + 2, mid + 1, right, index, new_value);
    }
    value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
}
// Q:区域和的查询（LeetCode 307）
class NumArray{
    public:
        NumArray(vector<int> nums){
            if(nums.size() == 0){
                return;
            }
            int n = nums.size() * 4;
            for(int i = 0; i < n; i++){
                _value.push_back(0);
            }
            bulid_segment_tree(_value, nums, 0, 0, nums.size() - 1);
            _right_end = nums.size() - 1;
        }
        void update(int i , int val){
            update_segment_tree(_value, 0, 0, _right_end, i, val);
        }
        int sumRange(int i, int j){
            return sum_range_segment_tree(_value, 0, 0, _right_end, i, j);
        }
    private:
        vector<int> _value;
        int _right_end;
};
int main()
{
    vector<int> vec{1,3,5};
    NumArray na(vec);
    cout << na.sumRange(0,2) << endl;
    na.update(1, 2);
    cout << na.sumRange(0,2) << endl;

    return 0;
}
