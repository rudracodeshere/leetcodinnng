class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = INT_MAX;
        int sell = INT_MIN;
        for(int price: prices){
            if(price<buy){
                buy = price;
                sell = buy;
                continue;
            }
            if(price>=sell){
                sell = price;
                ans = max(ans,sell-buy);
            }
        }
        return ans;
    }
};