class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> tab;
        for(int i = 0; i < nums.size(); i++){
            if(tab[nums[i]]){
                ++tab[nums[i]];
            }
            else{
                tab[nums[i]] = 1;
            }
        }
        int count = 0;
        int res;
        for(auto it : tab){
            if(it.second > count){
                count = it.second;
                res = it.first;
            }
        }
        return res;
    }
};