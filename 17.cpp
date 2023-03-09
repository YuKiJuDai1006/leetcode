class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        unordered_map<char, string> phone{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string com;
        backTrace(digits, res, phone, 0, com);
        return res;
    }

    void backTrace(string digits, vector<string>& res, 
        unordered_map<char, string> phone, int index, string com){
        if(index == digits.size()){
            res.push_back(com);
            return;
        }

        char c = digits[index];
        string str = phone.at(c);
        for(char ch : str){
            com.push_back(ch);
            backTrace(digits, res, phone, index+1, com);
            com.pop_back();
        }
    }

};