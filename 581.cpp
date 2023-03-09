class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minn = INT_MAX;
        int maxn = INT_MIN;

        int l = -1, r = -1;

        for(int i = 0; i < n; i++){
            if(nums[n-1-i] <= minn) minn = nums[n-1-i];
            else l = n-1-i;

            if(nums[i] >= maxn) maxn = nums[i];
            else r = i;
        }
        return l == -1 ? 0 : r-l+1;
    }
};