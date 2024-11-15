class Solution {
public:
    // void printMp(map<char, int> mp){
    //     for(auto& p : mp){
    //         cout<<p.first<<":"<<p.second<<endl;
    //     }
    //     cout<<"khatam"<<endl;
    // }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        map<char, int> mp;
        map<char, int> temp;
        for(char ch = 'a';ch<='z';ch++){
            mp[ch]=0;
            temp[ch]=0;
        }
        for (char ch : s1) {
            mp[ch]++;
        }

        int l = 0;
        int r = 0;
        // printMp(mp);
        
        while (r < s1.size()) {
            temp[s2[r]]++;
            r++;
        }
        if (mp == temp)
            return true;

        while (r < s2.size()) {
            temp[s2[l]]--;
            l++;
            temp[s2[r]]++;
            r++;
            // printMp(temp);
            if (mp == temp)
                return true;
        }
        return false;
    }
};