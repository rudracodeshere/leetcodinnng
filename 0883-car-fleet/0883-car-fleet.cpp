class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairArr;
        for(int i = 0;i<position.size();i++){
            pairArr.push_back({position[i],speed[i]});
        }
        sort(pairArr.rbegin(),pairArr.rend());
       
        stack<float> st;

        for (auto& p : pairArr) {
       
            float time = (float)(target - p.first) / p.second;
            
            
            if (st.size()>=1 && time <= st.top()) {
               continue;
            }
            else{
                st.push(time);
            }
        }
        return st.size();
    }
};