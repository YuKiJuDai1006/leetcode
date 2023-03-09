class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(string& word : wordDict){
            words.insert(word);
        }
        auto dp = vector <bool> (s.size()+1);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && words.count(s.substr(j, i-j))){
                    dp[i] = 1;
                }
            }
        }
        return dp[s.size()];
    }
};