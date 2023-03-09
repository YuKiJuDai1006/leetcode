class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int tar = n-k+1;
        map<int, int> tab;
        for(int i = 0; i < nums.size(); i++){
            tab[nums[i]]++;
        }
        for(auto it : tab){
            tar -= it.second;
            if(tar <= 0) return it.first;
        }
        return -1;
    }
};