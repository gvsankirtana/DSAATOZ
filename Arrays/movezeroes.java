class Solution {
    public void moveZeroes(int[] nums) {
        //brute force TC->O(2N) SC-> O(number of non zero)
        //store all the non zero to an array and add the remaining with 0
        //optimised solution 2-pointer approach TC->O(N) SC->O(1)
        int n = nums.length;
        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j!=-1){
            for(int i=j+1;i<n;i++){
                if(nums[i]!=0){
                    int temp = nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                    j++;
                }
            }
        }
    }
}
