class Solution {
public:
    string minWindow(string s, string t) {
        string com;
        vector<string> res;
        dfs(0, s, t, res, com, 0);
        string ans;
        int max = 10000;
        for(auto &it : res){
            if(it.size() < max) ans = it;
        }
        return ans;
    }

    void dfs(int lev, string s, string t, 
        vector<string>& res, string com, int flag){
        if(t.size() == 0) return;
        if(lev == s.size()) return;

        int idx = t.find(s[lev]);
        if(idx){
            if(flag == 0){
                dfs(lev+1, s, t, res, com, 0);

                com.push_back(s[lev]);
                t = t.erase(idx, idx);
                if(t.size() == 0){
                    res.push_back(com);
                    return;
                }
                dfs(lev+1, s, t, res, com, 1);
            }
            else{
                com.push_back(s[lev]);
                t = t.erase(idx, idx);
                if(t.size() == 0){
                    res.push_back(com);
                    return;
                }
                dfs(lev+1, s, t, res, com, 1);
            }
        }
        else{
            if(flag == 0){
                dfs(lev+1, s, t, res, com, 0);
            }
            else{
                com.push_back(s[lev]);
                dfs(lev+1, s, t, res, com, 1);
            }
        }
    }
};