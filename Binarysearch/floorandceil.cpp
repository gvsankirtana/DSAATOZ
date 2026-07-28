class Solution {
public:
    int findfloor(vector<int> nums, int x){
       int low = 0,high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=x){
                ans = nums[mid];
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    int findceil(vector<int> nums, int x){
        //using lower bound
        int low = 0,high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=x){
                ans = nums[mid];
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
         int ceil = findceil(nums,x);
         int floor = findfloor(nums,x);
         return {floor,ceil};
    }
};
