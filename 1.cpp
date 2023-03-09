1.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int toSearch = target - nums[i];
            for(int j = i + 1; j < n; j++){
                if(nums[j] == toSearch)
                    return {i, j};
            }
        }        
        return {};   
    }
};

1.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> ht;
        for(int i = 0; i < n; i++){
            auto it = ht.find(target - nums[i]);
                if(it != ht.end()){
                    return{i, it -> second};
                }
                ht[nums[i]] = i;
            }
        return {}; 
    }
};

