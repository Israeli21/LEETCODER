class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0, j = height.size() - 1;
            int maxH1 = height[i], maxH2 = height[j];
            int largest = 0;
            int tall, distance, area;
            while(i != j){
                tall = min(maxH1, maxH2);
                distance = j - i;
                area = tall * distance;
                if(area > largest)
                    largest = area;
                if(maxH1 > maxH2){
                    j--;
                    maxH2 = height[j];
                } else {
                    i++;
                    maxH1 = height[i];
                }
            }
            return largest;
        }
};

// O(n^2)
// int largest = 0, tall, distance, area;
//         for(int i = 0; i < height.size() - 1; i++){
//             for(int j = 1; j < height.size(); j++){
//                 tall = max(height[i], height[j]) - (max(height[i], height[j]) - min(height[i], height[j]));
//                 distance = j - i;
//                 area = tall * distance;
//                 if(area > largest)
//                     largest = area;
//             }
//         }
//         return largest;