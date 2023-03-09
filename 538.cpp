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
    TreeNode* convertBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(inorder, root);
        int n = inorder.size();
        
        int sum = 0;
        for(int i = n-1; i >=0; i--){
            inorder[i] += sum;
            sum = inorder[i];
        }
        int k = 0;
        myOrder(inorder, k, root);
        return root;
    }

    void inOrder(vector<int>& inorder, TreeNode* node){
        if(node){
            inOrder(inorder, node->left);
            inorder.push_back(node->val);
            inOrder(inorder, node->right);
        }
    }

    void myOrder(vector<int>& inorder, int& k, TreeNode* node){
        if(node){
            myOrder(inorder, k, node->left);
            node->val = inorder[k++];
            myOrder(inorder, k, node->right);
        }
    }
};