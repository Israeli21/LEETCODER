// C++ Program to Find Container with Most Water
#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int> &arr) {
    int n = arr.size();
    int area = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            // Calculating the max area
            area = max(area, min(arr[j], arr[i]) * (j - i));
        }
    }
    return area;
}

int main() {
    vector<int> a = {3, 1, 2, 4, 5};
    cout << maxArea(a);
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)


// C++ Program to Find Container with Most Water
// #include <vector>
// #include <iostream>
// using namespace std;

// int maxArea(vector<int>& arr) {
//     int n = arr.size();
//     int left = 0; 
//     int right = n -1;
//     int area = 0;
    
//     while (left < right) {
//         // Calculating the max area
//         area = max(area, min(arr[left], arr[right]) * (right - left));

//         if (arr[left] < arr[right])
//             left += 1;
//         else
//             right -= 1;
//     }
//     return area;
// }

// int main() {
//     vector<int> a = {3, 1, 2, 4, 5};
//     cout << maxArea(a);
// }

// Time Complexity: O(n)
// Space Complexity: O(1)