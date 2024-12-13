class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (char ch : tasks) {
            count[ch - 'A']++;
        }
        sort(count.rbegin(), count.rend());
        int blocks = count[0] - 1;
        int idle = blocks * n;
        for (int i = 1; i < 26; i++) {
            idle -= min(blocks, count[i]);
        }
        return idle <= 0 ? tasks.size() : tasks.size() + idle;
    }
};