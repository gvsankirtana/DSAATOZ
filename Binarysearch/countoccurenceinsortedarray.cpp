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
    int countOccurrences(vector<int>& arr, int target) {
        // Your code goes here
        int lb = lowerBound(arr,target);
        if(lb==arr.size()||arr[lb]!=target){
            return 0;
        }
        return ((upperBound(arr,target)-1)-lb)+1;
    }
};
