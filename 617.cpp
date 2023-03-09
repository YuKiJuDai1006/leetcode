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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = dfs(root1, root2);
        return root;
    }

    TreeNode* dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return nullptr;
        int v = 0;
        TreeNode* ret = new TreeNode();
        if(root1 && root2){
            v += root1->val + root2->val;
            ret->val = v;
            ret->left = dfs(root1->left, root2->left);
            ret->right = dfs(root1->right, root2->right);
        }
        if(root1 && !root2){
            v += root1->val;
            ret->val = v;
            ret->left = dfs(root1->left, nullptr);
            ret->right = dfs(root1->right, nullptr);
        }
        if(!root1 && root2){
            v += root2->val;
            ret->val = v;
            ret->left = dfs(nullptr, root2->left);
            ret->right = dfs(nullptr, root2->right);
        }
        return ret;
    }
};