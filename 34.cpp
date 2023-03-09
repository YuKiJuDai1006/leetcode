class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};

        if(n == 1){
            if(nums[0] == target){
                return {0, 0};
            }
            else return {-1, -1};
        }

        int count = 0;
        int flag = 1;
        int index;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                if(flag){
                    index = i;
                    flag = 0;
                }
                count++;
            }
        }
        if(count == 0) return{-1, -1};
        return{index, index+count-1};
    }
};