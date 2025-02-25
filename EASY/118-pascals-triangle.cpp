class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> answers = {{1}};
            if(numRows == 1)
                return answers;
            answers.push_back({1, 1});
            if(numRows == 2)
                return answers;
    
            for(int i = 2; i < numRows; i++){
                vector<int> ans = {1};
                vector<int> temp = answers.back();
                for(int j = 0; j < temp.size() - 1; j++){
                    ans.push_back(temp[j] + temp[j + 1]);
                }
                ans.push_back(1);
                answers.push_back(ans);
            }
    
            return answers;
        }
    };