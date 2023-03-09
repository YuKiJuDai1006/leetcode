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
    unordered_map<int, int> tab;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < preorder.size(); i++){
            tab[inorder[i]] = i;
        }
        return build(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
    TreeNode* build(int pre_l, int pre_r, int in_l, int in_r,
         vector<int>& preorder, vector<int>& inorder){
        if(pre_l >= pre_r){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_l]);
        int L = tab[preorder[pre_l]] - in_l;
        int R = in_r - tab[preorder[pre_l]];

        root->left = build(pre_l+1, pre_l+1+L, in_l, in_l+L, preorder, inorder);
        root->right = build(pre_l+1+L, pre_l+L+R, tab[preorder[pre_l]] + 1,
                            in_r, preorder, inorder);

        return root;
    }
};