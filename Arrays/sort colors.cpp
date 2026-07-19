class Solution {
public:
    void sortColors(vector<int>& nums) {
        //brute force is sorting TC->O(NlogN) SC->O(N)
        //better solution is using loops and having seperate count for 0,1and 2 and replacing
        //TC->O(2N) SC->O(1)
        //optimal solution dutch national flag algorithm TC->O(N) SC->O(1)
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
