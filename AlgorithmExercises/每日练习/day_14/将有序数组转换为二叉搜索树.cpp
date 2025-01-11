#if 0
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 
平衡
 二叉搜索树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* dfs(vector<int>&nums,int left,int right){
        if(left == right){
            return nullptr;
        }
        int m = left + ((right - left) >> 1);
        return new TreeNode(nums[m],dfs(nums,left,m),dfs(nums,m+1,right));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size());   
    }
};
#endif