/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        unordered_map<int, TreeNode*> tab1;
        unordered_map<int, bool> tab2;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        while(p){
            tab2[p->val] = 1;
            p = tab1[p->val];
        }
        while(q){
            if(tab2[q->val] == 1) return q;
            q = tab1[q->val];
        }
        return nullptr;

    }
    void dfs(TreeNode* node){
        if(node->left){
            tab1[node->left->val] = node;
            dfs(node->left);
        }
        if(node->right){
            tab1[node->right->val] = node;
            dfs(node->right);
        }
    }
};