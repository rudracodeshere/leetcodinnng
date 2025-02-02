class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)return {};
        vector<vector<int>> ans = {{1}};
        for(int i = 1;i<numRows;i++){
            vector<int> curr;
            for(int j = 0;j<=i;j++){
                if(j-1<0||j+1>i){
                    curr.push_back(1);
                }
                else{
                    int a = ans[i-1][j-1];
                    int b = ans[i-1][j];
                    curr.push_back(a+b);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};