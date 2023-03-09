class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, j;
        for(i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                break;
            }
        }

        if(i == 0){
            sort(nums.begin(), nums.end());
            return;
        }

        for(j = n-1; j > 0; j--){
            if(nums[j] > nums[i-1]){
                break;
            }
        }

        int temp = nums[i-1];
        nums[i-1] = nums[j];
        nums[j] = temp;
        
        sort(nums.begin()+i, nums.end());
    }
};