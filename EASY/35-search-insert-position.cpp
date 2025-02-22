class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int R = nums.size() - 1;
            int L = 0, mid;
            while(R >= L){
                mid = (L + R)/2;
                if(target == nums[mid]) return mid;
                else if(target > nums[mid]) L = mid + 1;
                else R = mid - 1;
            }
    
            return L;
        }
    };