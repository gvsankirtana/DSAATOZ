class Solution {
public:
int sumofd(vector<int>& nums, int div){
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum = sum + ceil((double)nums[i]/(double)div);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
      //brute force TC->O(max x N)
      //optimised solution using binary search on answers TC->O(log(max)xN)
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(sumofd(nums,mid)<=threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
