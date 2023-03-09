class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if(n == 1) return res;

        int l = 1, r = n-2, lm = 0, rm = n-1;

        while(l <= r){
            if(height[lm] < height[rm]){
                if(height[lm] > height[l]){
                    res += height[lm] - height[l];
                }
                else
                    lm = l;
                l++;
            }
            else{
                if(height[rm] > height[r]){
                    res += height[rm] - height[r];
                }
                else
                    rm = r;
                r--;
            }
        }
        return res;
    }
};