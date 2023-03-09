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
    void flatten(TreeNode* root) {
        if(!root) return;

        vector<int> nums;
        preOrder(root, nums);
        TreeNode* Nroot = new TreeNode(root->val);
        TreeNode* v = Nroot;
        for(int i = 1; i < nums.size(); i++){
            TreeNode* u = new TreeNode(nums[i]);
            v->right = u;
            v = v->right;
        }
        root->left = nullptr;
        root->right = Nroot->right;
    }

    void preOrder(TreeNode* node, vector<int>& nums){
        if(node){
            nums.push_back(node->val);
            preOrder(node->left, nums);
            preOrder(node->right, nums);
        }
    }
};