class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tab1;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ++tab1[nums[i]];
        }
        map<int, int, greater<int>> tab2;
        for(auto& it : tab1){
            tab2[it.second] = it.first;
        }
        for(auto& it : tab2){
            ans.push_back(it.second);
            --k;
            if(k == 0) return ans;
        }
        return ans;
    }
};