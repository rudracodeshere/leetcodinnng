class Solution {
public:
    map<int, vector<int>> preqs;
    set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            preqs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i))
                return false;
        }
        return true;
    }
    bool dfs(int course) {
        if (visited.contains(course))
            return false;
        if (preqs[course].empty())
            return true;
        visited.insert(course);
        for (int i : preqs[course]) {
            if (!dfs(i))
                return false;
        }
        visited.erase(course);
        preqs[course].clear();
        return true;
    }
};