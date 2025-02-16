#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to find a triplet with a given sum in an array
bool find3Numbers(vector<int>& arr, int sum){
    int n = arr.size();
    
    // Sort the elements
    sort(arr.begin(), arr.end());

    // Fix the first element one by one and find the other two elements
    for (int i = 0; i < n - 2; i++) {

        // To find the other two elements, start two index variables from two corners of the array and move them toward each other
        int l = i + 1;  // index of the first element in the remaining elements
        int r = n - 1;  // index of the last element

        while (l < r) {
            int curr_sum = arr[i] + arr[l] + arr[r];
            if (curr_sum == sum) {
                cout << "Triplet is " << arr[i] << ", "
                    << arr[l] << ", " << arr[r];
                return true;
            } else if (curr_sum < sum)
                l++;
            else // curr_sum > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}

int main(){
    vector<int> arr = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    find3Numbers(arr, sum);
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)