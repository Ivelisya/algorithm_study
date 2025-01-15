#if 0
给你一个 二叉树 的根结点 root，该二叉树由恰好 3 个结点组成：根结点、左子结点和右子结点。

如果根结点值等于两个子结点值之和，返回 true ，否则返回 false 。
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
public:
    bool checkTree(TreeNode* root) {
        return (root -> val) == (root -> left) -> val + (root -> right) -> val;
    }
};
#endif