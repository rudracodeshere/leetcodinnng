class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>>
            pq;
        for (auto& point : points) {
            int temp1 = point[0] * point[0];
            int temp2 = point[1] * point[1];
            pq.push({temp1 + temp2, point});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};