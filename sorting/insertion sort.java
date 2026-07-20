class Solution {
  //TC-->O(N^2) worst and avg best case --> O(N)
    public int[] insertionSort(int[] nums) {
       int n = nums.length;
       for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0&&nums[j-1]>nums[j]){
            int temp = nums[j-1];
            nums[j-1]=nums[j];
            nums[j]=temp;
            j--;
        }
       }
       return nums;
    }
}
