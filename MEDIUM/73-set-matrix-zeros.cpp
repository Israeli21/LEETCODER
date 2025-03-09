class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            vector<vector<int>> change;
            int numRows = matrix.size();
            int numCols = matrix[0].size();
            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < numCols; j++){
                    if(matrix[i][j] == 0)
                        change.push_back({i, j});
                }
            }
    
            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < numCols; j++){
                    for(int c = 0; c < change.size(); c++){
                        if(i == change[c][0] || j == change[c][1]){
                            matrix[i][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    };