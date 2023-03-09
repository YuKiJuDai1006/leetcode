class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return 0;
        int tar = sum >> 1;

        vector<vector<bool>> dp(n, vector<bool>(sum));
        dp[0][nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= tar; j++){
                if(dp[i-1][j] || j == nums[i])
                    dp[i][j] = 1;
                if(j >= nums[i] && dp[i-1][j-nums[i]])
                    dp[i][j] = 1;
            }
        }
        return dp[n-1][tar];
    }
};