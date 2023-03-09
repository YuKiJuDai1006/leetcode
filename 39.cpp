class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> com;
        dfs(candidates, target, 0, com, res);
        return res;
    }

    void dfs(vector<int> candidates, int target, int idx,
     vector<int> com, vector<vector<int>>& res){
        if(idx == candidates.size()) return;

        if(target == 0){
            res.push_back(com);
            return;
        }

        dfs(candidates, target, idx+1, com, res);

        if(target - candidates[idx] >= 0){
            com.push_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], idx, com, res);
        }

    }
};