class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int high;
        for(int i = 1; i <= n; i++){
            if((i & (i-1)) == 0){
                high = i;
            }
            ans[i] = ans[i-high] + 1;
        }
        return ans;
    }
};