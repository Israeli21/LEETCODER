// NAIVE Solution: Recursive
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void letterCombinations(const vector<int> &a, vector<string> &mp, int i, string curr, vector<string> &res){
    // If we have used a mapping for every digit
    if (i == a.size()){
        res.push_back(curr);
        return;
    }

    // Get all characters mapped to current digit. 
    string chars = mp[a[i]];
  
    // Add every character to the res and make
    // a recursive call for the next digit.
    for (int c = 0; c < chars.length(); c++)
        letterCombinations(a, mp, i + 1, curr + chars[c], res);
}

// Function to find list of all words possible by pressing given numbers.
vector<string> possibleWords(const vector<int> &a){
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    letterCombinations(a, mp, 0, "", res);
    return res;
}

int main(){
    vector<int> a = {2, 3};
    vector<string> res = possibleWords(a);
    for (const string &word : res)
        cout << word << " ";
    return 0;
}

// Time Complexity: O(n * k^n)
// Space Complexity: O(n + n * k^n)

// res = "ad, "

// letterCombinations(a, mp, 0, "", res), c = 0;
// letterCombinations(a, mp, 1, "a", res), c = 0;
// letterCombinations(a, mp, 2, "ad", res), c = NULL; UP STACK
// letterCombinations(a, mp, 1, "a", res), c = 1;
// letterCombinations(a, mp, 2, "ae", res), c = NULL; UP STACK
// letterCombinations(a, mp, 1, "a", res), c = 2;
// letterCombinations(a, mp, 2, "af", res), c = NULL; UP STACK
// letterCombinations(a, mp, 1, "a", res), c = COMPROMISED (3); UP STACK

// letterCombinations(a, mp, 0, "", res), c = 1;
// letterCombinations(a, mp, 1, "b", res), c = 0;
// letterCombinations(a, mp, 2, "bd", res), c = NULL; UP STACK


// // Efficient Solution: Queues
// #include <bits/stdc++.h>
// using namespace std;

// // Function to return a vector that contains all the 
// // generated letter combinations
// vector<string> letterCombinations(vector<int> &a)
// {
//     // mp[i] stores all characters that correspond to ith digit in phone
//     string mp[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

//     // To store the generated letter combinations
//     vector<string> res;

//     // Queue to store intermediate combinations
//     queue<string> q;
//     q.push("");

//     // Process combinations using BFS-like approach
//     while (!q.empty()) {
//         string s = q.front();
//         q.pop();

//         // If complete word is generated, 
//         // add to the result list
//         if (s.length() == a.size()) {
//             res.push_back(s);
//         } else {
//             // Try all possible letters for the
//             // current digit in the vector a
//             for (char c : mp[a[s.length()]]) {
//                 q.push(s + c);
//             }
//         }
//     }
//     // Return the generated combinations
//     return res;
// }

// // Driver code
// int main(){
//     vector<int> a = {2, 3}; 
//     vector<string> res = letterCombinations(a);
//     for (const string &word : res) 
//         cout << word << " ";
//     return 0;
// }

// // Time Complexity: O(4^n)
// // Space Complexity: O(4^n)