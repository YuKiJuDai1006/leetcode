class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> f(n);
        vector<int> g(n);
        if(nums[0] > 0){
            f[0] = nums[0];
            g[0] = 0;
        }
        else{
            f[0] = 0;
            g[0] = nums[0];
        }
        for(int i = 1; i < n; i++){
            if(nums[i] > 0){
                f[i] = max(f[i-1]*nums[i], nums[i]);
                g[i] = g[i-1]*nums[i];
            }
            else{
                f[i] = g[i-1]*nums[i];
                g[i] = min(f[i-1]*nums[i], nums[i]);
            }
        }
        
        return *max_element(f.begin(), f.end());
    }
};