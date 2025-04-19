class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;

            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                if(mid-2>=l && ((mid-2)-l)%2==0){
                    r = mid-2;
                }
                else{
                   l = mid+1; 
                }
            }
            else if(mid+1<=r && nums[mid+1]==nums[mid]){
                if(mid-1>=l && ((mid-1)-l)%2==0){
                    r = mid-1;
                }
                else{
                    l = mid+2;
                }
            }
            else return nums[mid];
            
        }
        return -1;
    }
};