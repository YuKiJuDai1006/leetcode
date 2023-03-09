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
    int rob(TreeNode* root) {
        int l1, l2, r1, r2;
        dfs(root, l1, l2, r1, r2, 0);
        return max(l1 ,l2);
    }
    void dfs(TreeNode* node, int& l1, int& l2, int& r1, int& r2, int flag){
        if(!node){
            if(flag == 0){
                l1 = 0;
                l2 = 0;
            }
            else{
                r1 = 0;
                r2 = 0;
            }
            return;
        }

        else{
            dfs(node->left, l1, l2, r1, r2, 0);
            int L1 = l1, L2 = l2;
            dfs(node->right, l1, l2, r1, r2, 1);
            int R1 = r1, R2 = r2;
            if(flag == 0){
                l1 = max(L1, L2) + max(R1, R2);
                l2 = L1 + R1 + node->val;
            }
            else{
                r1 = max(L1, L2) + max(R1, R2);
                r2 = L1 + R1 + node->val;
            }
        }
    }
};