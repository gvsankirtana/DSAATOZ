class Solution {
public:
    int lowerBound(vector<int> &nums, int x){
        int low = 0,high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int x){
        int low = 0,high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //brute force by iterating linear way TC->O(n)
        //better solution use upper bound and lower bound TC->O(2*logn)
        int lb = lowerBound(nums,target);
        if(lb==nums.size()||nums[lb]!=target){
            return {-1,-1};
        }
        return {lb,upperBound(nums,target)-1};
    }
};
