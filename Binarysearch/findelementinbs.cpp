class Solution {
public:
    //TC->O(log n) SC->O(log n) for recurison
    int find(vector<int>& nums, int low, int high,int target){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(nums[mid]==target) return mid;
        if(target>nums[mid]){
            return find(nums,mid+1,high,target);
        }
        return find(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        //iterative solution
        int low = 0 ,high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid])low = mid+1;
            else high = mid-1;
        }
        return -1;
        //recursive solution
        return find(nums,0,nums.size()-1,target);
    }
};
