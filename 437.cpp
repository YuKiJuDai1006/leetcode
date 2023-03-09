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
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
    void dfs(TreeNode* node, int targetSum){
        if(node){
            check(node, targetSum);
            dfs(node->left, targetSum);
            dfs(node->right, targetSum);
        }
    }
    void check(TreeNode* node, long long target){
        if(node){
            if(node->val == target) res++;
            check(node->left, target - node->val);
            check(node->right, target - node->val);
        }
    }
};