class TimeMap {
public:
    map<string, vector<pair<string, int>>> mp;

    void set(string key, string value, int timestamp) {
        pair<string, int> p = {value, timestamp};
        mp[key].push_back(p);
    }

    string get(string key, int timestamp) {
        string ans;
        int l = 0;
        int r = mp[key].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mp[key][mid].second == timestamp) {
                return mp[key][mid].first;
            }
            if (mp[key][mid].second < timestamp) {
                ans = mp[key][mid].first;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};
