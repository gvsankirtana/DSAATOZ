class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        //brute force TC->O(n)
        //optimal solution TC->O(logn)
        int n = nums.size();
        int low=0,high=n-1,ans=INT_MAX;
        int index=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[high]){
                if(nums[low]<ans){
                    index = low;
                    ans = nums[low];
                    break;
                }
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<ans){
                    ans = nums[low];
                    index = low;
                }
                low = mid+1;
            }
            else{
                if(nums[mid]<ans){
                    ans = nums[mid];
                    index = mid;
                }
                high = mid-1;
            }
        }
        return index;
    }
};
