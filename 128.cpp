class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(const int& num : nums){
            st.insert(num);
        }
        int res = 0;
        int count = 0;

        for(const int& num: st){
            if(!st.count(num-1)){
                int tmp = num;
                while(st.count(tmp)){
                    ++count;
                    ++tmp;
                }
                res = max(res, count);
                count = 0;
            }
        }
        return res;
    }
};