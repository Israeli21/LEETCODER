#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    Solution s;
    vector<vector<int>> output = s.generate(5);
    
    cout << "[";
    for(int i = 0; i < output.size(); i++){
        cout << "[";
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j];
            if(j != output[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if(i != output.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}