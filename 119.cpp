class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx = prices.size()-1;
        int res = 0;
        for(int i = prices.size()-2; i >= 0; i--){
            if(prices[i] < prices[idx]){
                res = max(res, prices[idx] - prices[i]);
            }
            else idx = i;
        }
        return res;
    }
};