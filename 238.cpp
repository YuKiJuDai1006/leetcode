class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n);
        l[0] = 1;
        for(int i = 1; i < n; i++){
            l[i] = l[i-1] * nums[i-1];
        }
        int r = nums[n-1];
        for(int j = n-2; j >= 0; j--){
            l[j] *= r;
            r *= nums[j];
        }
        return l;
    }
};