class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int cover[10001] = {0};
        vector<vector<int>> ans;
        for(auto &it : intervals){
            for(int i = it[0]; i < it[1]; i++){
                cover[i] = 1;
            }
        }
        int flag = 0;
        int pre;
        for(int i = 0; i < 10001; i++){
            if(cover[i] == 0){
                if(flag == 1){
                    ans.push_back({pre, i});
                    flag = 0;
                }
                continue;
            }

            else{
                if(flag == 0){
                    pre = i;
                    flag = 1;
                    continue;
                }
                if(flag == 1) continue;
            }
        }

        for(auto &it : intervals){
            if(it[0] == 0 && it[1] == 0){
                if(cover[0] == 0){
                    ans.push_back({0, 0});
                    cover[0] = 2;
                }
                continue;
            }
            if(it[0] == it[1]){
                if(cover[it[0]] == 1 || cover[it[0]-1] == 1) continue;
                else{
                    if(cover[it[0]] != 2){
                        ans.push_back({it[0], it[0]});
                        cover[it[0]] = 2;
                    }   
                }
            }
        }
        return ans;
    }
};