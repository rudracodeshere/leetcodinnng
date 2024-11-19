class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                int tempAns = i - st.top().second;
                res[st.top().second] = tempAns;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};