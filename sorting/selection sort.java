class Solution {
    public int[] selectionSort(int[] nums) {
        int n = nums.length;
        int mini=0;
        for(int i=0;i<=n-2;i++){
            mini=i;
            for(int j=i;j<=n-1;j++){
                if(nums[j]<nums[mini]){
                    mini=j;
                }
            }
            int temp = nums[mini];
            nums[mini] = nums[i];
            nums[i] = temp;
        }
        return nums;
    }
}
