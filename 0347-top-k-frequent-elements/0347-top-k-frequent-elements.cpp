class Solution {
  
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> arr;

        for (auto p : mp) {
            arr.push_back(p);
        }

        sort(arr.begin(), arr.end(), comp);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};