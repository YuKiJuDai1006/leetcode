class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            dp[i] = sum + nums[i];
            sum = dp[i];
        }
        int res = 0;
        unordered_map<int, int> hs;
        for(int i = 0; i < n; i++){
            if(dp[i]-k == 0) ++res;
            if(hs.find(dp[i]-k) != hs.end())
                res += hs[dp[i]-k];
            
            ++hs[dp[i]];
        }
        return res;
    }
};