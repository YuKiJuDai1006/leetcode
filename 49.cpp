class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ht;
        
        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            ht[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto iter = ht.begin(); iter != ht.end(); iter++){
            res.push_back(iter->second);
        }
        return res;
    }
};