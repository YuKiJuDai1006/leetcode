class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int tar = n-1;
        for(int i = n-1; i >= 0; i--){
            if(tar - i <= nums[i]){
                tar = i;
            }
        }
        if(tar == 0) return 1;
        return 0;
    }
};