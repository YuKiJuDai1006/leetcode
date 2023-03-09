class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> qe;
        for(int i = 0; i < k; i++){
            qe.emplace(nums[i], i);
        }
        vector<int> ans;
        ans.push_back(qe.top().first);
        for(int i = k; i < n; i++){
            qe.emplace(nums[i], i);
            while(qe.top().second <= i-k) qe.pop();
            ans.push_back(qe.top().first);
        }
        return ans;
        

    }
};