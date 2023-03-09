class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> com;
        dfs(res, nums, 0, com);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums,
     int idx, vector<int>& com){
        if(idx == nums.size()){
            res.push_back(com);
            return;
        }
        dfs(res, nums, idx+1, com);

        com.push_back(nums[idx]);
        dfs(res, nums, idx+1, com);
        com.pop_back();
    }
};