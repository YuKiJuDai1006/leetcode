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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> qe1, qe2;
        if(!root) return {};
        qe2.push(root);
        TreeNode* u;
        while(!qe2.empty()){
            while(!qe2.empty()){
                qe1.push(qe2.front());
                qe2.pop();
            }
            vector<int> com;
            while(!qe1.empty()){
                u = qe1.front(); qe1.pop();
                if(u){
                    qe2.push(u->left);
                    qe2.push(u->right);
                    com.push_back(u->val);
                }
            }
            if(com.size()) res.push_back(com);
        }
        return res;
    }
};