class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int zeros = -1;
            int ones = -1;
            int twos = -1;
            
            for(const int num:nums){
                if(num == 0){
                    nums[++twos] = 2;
                    nums[++ones] = 1;
                    nums[++zeros] = 0;
                } else if(num == 1){
                    nums[++twos] = 2;
                    nums[++ones] = 1;
                } else {
                    nums[++twos] = 2;
                }
            }
        }
    };