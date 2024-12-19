class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> smap;
        map<char, int> tmap;

        for (int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        int count = 0;
        for (auto p : smap) {
            if (p.second > tmap[p.first]) {
                count = count + (p.second - tmap[p.first]);
            }
        }

        return count;
    }
};