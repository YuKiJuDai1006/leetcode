class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return res;

        int i = 0;
        while(i < n){
            if(nums[i] > 0) break;
            int li = i+1, ri = n-1;
            while(li < ri){
                if(nums[i] + nums[li] + nums[ri] > 0) ri--;
                else if(nums[i] + nums[li] + nums[ri] < 0) li++;

                else{
                    res.push_back({nums[i], nums[li], nums[ri]});
                    while(li < ri && nums[li] == nums[li+1]) li++;
                    while(li < ri && nums[ri] == nums[ri-1]) ri--;
                    li++;
                    ri--;
                }
            }
            while(i < n-2 && nums[i] == nums[i+1]) i++;
            i++;
        }
        return res;
    }
};