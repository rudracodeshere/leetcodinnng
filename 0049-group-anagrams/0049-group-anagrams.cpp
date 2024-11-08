#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str: strs){
            string org = str;
            sort(str.begin(),str.end());
            mp[str].push_back(org);
        }
        vector<vector<string>> ans;
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};