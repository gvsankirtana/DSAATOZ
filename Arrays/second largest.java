class Solution {
    public int secondLargestElement(int[] nums) {
        //brute force TC - NLOGN + N
        Arrays.sort(nums);
        int largest = nums[nums.length-1];
        int secondlargest = -1;
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i]!=largest){
               secondlargest = nums[i];
               break;
            }
        }
        return secondlargest;
        //Better Solution
        //find the largest element 
        for(int i=0;i<n;i++){
            if(arr[i]>slargest && arr[i]!=largest){
                slargest=arr[i];
            }
        }
        return slargest
        //optimal Solution
        int largest = nums[0];
        int slargest = -1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]>largest){
                slargest = largest;
                largest=nums[i];
            }
            else if(nums[i]<largest && nums[i]>slargest){
                slargest = nums[i];
            }
        }
        return slargest;
    }
}
