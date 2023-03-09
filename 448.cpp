class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for(int i = 0; i < n; i++){
            nums[(nums[i] - 1) % n] += n;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] <= n) ret.push_back(i+1);
        }
        return ret;
    }
};