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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        int pre = res[0];
        for(int i = 1; i < res.size(); i++){
            if(res[i] <= pre) return 0;
            pre = res[i];
        }
        return 1;
    }
    void inOrder(TreeNode* node, vector<int>& res){
        if(node){
            inOrder(node->left, res);
            res.push_back(node->val);
            inOrder(node->right, res);
        }
    }
};