class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() == 0 || s1.size() > s2.size())
            return false;
        map<char, int> sOne, sTwo;
        for (auto& ch : s1) {
            sOne[ch]++;
        }
        int l = 0;
        int r = 0;
        while (r < s1.size()) {
            sTwo[s2[r]]++;
            r++;
        }

        if (sOne == sTwo)
            return true;

        while (r < s2.size()) {
            sTwo[s2[l]]--;
            if (sTwo[s2[l]] == 0)
                sTwo.erase(s2[l]);
            l++;

            sTwo[s2[r]]++;
            if (sOne == sTwo)
                return true;
            r++;
        }
        return false;
    }
};