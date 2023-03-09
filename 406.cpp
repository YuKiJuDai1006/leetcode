class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        for(int k = 0; k < n; k++){
            for(int i = n-1; i > k; i--){
                if(people[i][0] > people[i-1][0]) swap(people[i], people[i-1]);
                if(people[i][0] == people[i-1][0]){
                    if(people[i][1] < people[i-1][1]) swap(people[i], people[i-1]);
                }
            }
        }

        vector<vector<int>> ans(n);
        int count = 0;
        for(int i = 0; i < n; i++){
            int idx = people[i][1];
            if(idx == count){
                ans[idx] = people[i];
                ++count;
            }
            else{
                for(int i = count; i > idx; i--){
                    ans[i] = ans[i-1];
                }
                ans[idx] = people[i];
                ++count;
            }
        }
        return ans;

    }
};