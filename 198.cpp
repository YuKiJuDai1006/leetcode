class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> tab(n);
        tab[0] = nums[0];
        tab[1] = nums[1];
        for(int i = 2; i < n; i++){
            tab[i] = Mmax(i-1, tab) + nums[i];
        }
        return *max_element(tab.begin(), tab.end());
    }
    int Mmax(int l, vector<int>& tab){
        return *max_element(tab.begin(), tab.begin()+l);
    }
};