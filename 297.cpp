/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preOrder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> tab;
        string temp;
        for(char& ch : data){
            if(ch == ','){
                tab.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(ch);
            }
        }
        return build(tab);
    }

    TreeNode* build(list<string>& tab){
        if(!tab.size()) return nullptr;
        if(tab.front() == "None"){
            tab.erase(tab.begin());
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tab.front()));
        tab.erase(tab.begin());
        node->left = build(tab);
        node->right = build(tab);
        return node;
    }


    void preOrder(TreeNode* node, string& res){
        if(!node) res += "None,";
        else{
            res += to_string(node->val) + ",";
            preOrder(node->left, res);
            preOrder(node->right, res);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));