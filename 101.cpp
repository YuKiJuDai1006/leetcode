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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> qe;
        if(!root->left && !root->right) return 1;

        qe.push(root->left);
        qe.push(root->right);
        TreeNode* u, *v;

        while(!qe.empty()){
            u = qe.front(); qe.pop();
            v = qe.front(); qe.pop();
            if(!u && !v) continue;
            if(!u || !v) return 0;
            if(u->val != v->val) return 0;
            qe.push(u->left);
            qe.push(v->right);

            qe.push(u->right);
            qe.push(v->left);
        }
        return 1;
    }
};