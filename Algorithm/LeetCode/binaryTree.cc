#include <iostream>
#include <vector>

using namespace std;

// Q1: LeetCode113

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution1 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int path_sum = 0;
        preorder(root, res, path, path_sum, sum);
        return res;
    }
private:
    void preorder(TreeNode* node, vector<vector<int>>& res, vector<int>& path, int& path_sum, int sum){
        if(!node){
            return;
        }
        path_sum += node->val;
        path.push_back(node->val);
        if(!node->left && !node->right && sum == path_sum){
            res.push_back(path);
        }
        preorder(node->left, res, path, path_sum, sum);
        preorder(node->right, res, path, path_sum, sum);
        
        path_sum -= node->val;
        path.pop_back();
    }
};
// Q2: LeetCode 114
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        preorder(root, last);
    }
private:
    void preorder(TreeNode* node, TreeNode*& last){
        if(!node){
            return;
        }
        if(!node->left && !node->right){
            last = node;
            return;
        }
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        TreeNode* left_last = NULL;
        TreeNode* right_last = NULL;
        if(left){
            preorder(left, left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right){
            preorder(right, right_last);
            if(left_last){
                left_last->right = right;
            }
            last = right_last;
        }
    }
};
// Q3: 二叉树的右视图
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution3 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;// 保存按成遍历的最后一个结点
        queue<pair<TreeNode*, int>> Q;// 保存结点和层数
        if(root){
            Q.push(make_pair(root, 0));
        }
        while(!Q.empty()){
                TreeNode* node = Q.front().first;
                int depth = Q.front().second;
                Q.pop();
                if(view.size() == depth){
                    view.push_back(node->val);
                }
                else{
                    view[depth] = node->val;
                }
            
            if(node->left){
                Q.push(make_pair(node->left, depth + 1));
            }
            if(node->right){
                Q.push(make_pair(node->right, depth + 1));
            }
                
            }
        return view;
    }
};
int main()
{

    return 0;
}
