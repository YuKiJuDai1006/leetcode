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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int l = dfs(root->left);
        int r = dfs(root->right);
        return max(res, l + r);
    }

    int dfs(TreeNode* node){
        if(!node) return 0;

        int L = dfs(node->left);
        int R = dfs(node->right);

        res = max(res, L+R);
        return max(L, R) + 1;
    }
};