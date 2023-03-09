class Solution {
public:
    int res = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return res;
    }

    void dfs(vector<int>& nums, int target, int idx){
        if(target == 0 && idx == nums.size()){
            ++res;
            return;
        }
        if(idx == nums.size()) return;

        dfs(nums, target+nums[idx], idx+1);
        dfs(nums, target-nums[idx], idx+1);
    }
};