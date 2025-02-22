// C++ program to count number of ways to reach 
// nth stair using memoization
#include <iostream>
#include <vector>
using namespace std;

int countWaysRec(int n, vector<int>& memo) {
  
    // Base cases
    if (n == 0 || n == 1)
        return 1;

    // if the result for this subproblem is already computed then return it
    if (memo[n] != -1) 
        return memo[n];
    
    return memo[n] = countWaysRec(n - 1, memo) + countWaysRec(n - 2, memo);
}

int countWays(int n) {
    // Memorization array to store the results
    vector<int> memo(n + 1, -1);
    return countWaysRec(n, memo);
}

int main() {
    int n = 4;
    cout << countWays(n);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)


// C++ program to count number of ways to
// reach nth stair using Space Optimized DP
// #include <iostream>
// #include <vector>
// using namespace std;

// int countWays(int n) {
  
//     // variable prev1, prev2 to store the
//       // values of last and second last states 
//     int prev1 = 1;
//     int prev2 = 1;
  
//     for(int i = 2; i <= n; i++) {
//         int curr = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = curr;
//     }
  
//       // In last iteration final value
//       // of curr is stored in prev.
//     return prev1;
// }

// int main() {
//     int n = 4;
//     cout << countWays(n);
//     return 0;
// }

// Time Complexity: O(n)
// Space Complexity: O(1)