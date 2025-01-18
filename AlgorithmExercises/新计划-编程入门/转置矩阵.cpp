#if 0
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n,vector<int>(length));
        for(int i = 0;i < n;++i){
            vector<int> element;
            for(int j = 0;j < length;++j){
                result[i][j] = matrix[j][i];
            }
        }
        return result;
        
    }
};
#endif