class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];
            int final_end = current_end;
            while(i<n && intervals[i][0]<=final_end){
                final_end = max(final_end,intervals[i][1]);
                i++;
            }
            i--;
            ans.push_back({current_start,final_end});
        }
        return ans;
    }
};