class Solution {
    public int largestElement(int[] nums) {
    //bruteforce TC-NLOGN
    // Arrays.sort(nums);
    // return nums[nums.length - 1];

    //optimal approch TC ->  O(N)
    int largest = nums[0];
    for(int i=0;i<nums.length;i++){
        if(nums[i]>largest){
            largest=nums[i];
        }
    }
    return largest;
    }
}
