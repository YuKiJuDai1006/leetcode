class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            if(dp[i-1] <= 0){
                dp[i] = nums[i];
            }
            else{
                dp[i] = dp[i-1] + nums[i];
            }
        }
        int max = dp[0];
        for(int i = 0; i < n; i++){
            if(dp[i] > max) max = dp[i];
        }
        return max;
    }
};