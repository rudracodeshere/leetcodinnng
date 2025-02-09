class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int price:prices){
             mini = min(mini,price);
            int current = price-mini;
            ans = max(ans,current);
           
        }
        return ans;
    }
};