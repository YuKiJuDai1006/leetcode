class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target? 0 : -1;


        int li = 0;
        int ri = n-1;
        
        while(li <= ri){
            int mid = (li + ri) / 2;
            if(nums[mid] == target) return mid;

            if(nums[li] <= nums[mid]){ // 左有序
                if(target >= nums[li] && target < nums[mid]){
                    ri = mid - 1;
                    continue;
                }
                else{
                    li = mid + 1;
                    continue;
                }
            }

            if(nums[mid] <= nums[ri]){ // 右有序
                if(target > nums[mid] && target <= nums[ri]){
                    li = mid + 1;
                    continue;
                }
                else{
                    ri = mid - 1;
                    continue;
                }
            }      
        }
        
        return -1;
    }
};