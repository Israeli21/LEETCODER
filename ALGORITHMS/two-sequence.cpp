#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the score function
int score(char a, char b) {
    if (a == '-' || b == '-') return -1; // Gap penalty
    return (a == b) ? 1 : 0; // +1 for match, 0 for mismatch
}

int SimScoreDP(const string &s, const string &t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = -i; // Filling first column
    for (int j = 0; j <= n; j++) dp[0][j] = -j; // Filling first row

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int align_t = dp[i][j - 1] + score('-', t[j - 1]); // Aligning gap with t[j]
            int align_s = dp[i - 1][j] + score(s[i - 1], '-'); // Aligning gap with s[i]
            int align_both = dp[i - 1][j - 1] + score(s[i - 1], t[j - 1]); // Align normally
            
            dp[i][j] = max({align_t, align_s, align_both});
        }
    }

    return dp[m][n]; // The final similarity score
}

int main() {
    string s = "AGTACGCA";
    string t = "AGTACGC";
    
    cout << "Optimal alignment score: " << SimScoreDP(s, t) << endl;
    return 0;
}
