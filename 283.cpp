class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for( ; i < n; i++){
            if(nums[i]) nums[j++] = nums[i];
        }
        while(j < n) nums[j++] = 0;
        
    }
};