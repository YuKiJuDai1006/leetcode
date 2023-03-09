class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f = 0, s = 0;
        f = nums[nums[f]];
        s = nums[s];
        while(f != s){
            f = nums[nums[f]];
            s = nums[s];
        }
        f = 0;
        while(f != s){
            f = nums[f];
            s = nums[s];
        }
        return f;
    }
};