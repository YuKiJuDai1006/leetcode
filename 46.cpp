class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> com;
        dfs(nums, res, com);
        return res;
    }

    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int> com){
        if(nums.size() == 0){
            res.push_back(com);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            com.push_back(nums[i]);
            vector<int> copy = nums;
            copy.erase(copy.begin() + i);
            dfs(copy, res, com);
            com.pop_back();
        }

    }
};