class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int count = 0;
        for(int num:nums){
            if(count == 0){
                el = num;
                count++;
            }
            else if(num == el){
                count++;
            }
            else{
                count--;
            }
        }

        return el;
    }
};