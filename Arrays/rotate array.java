class Solution {
     private void reverse(int[] arr, int left, int right) {
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    public void rotate(int[] nums, int k) {

        //brute force TC->O(n+d) sc->O(d)
        // k = k%nums.length;
        // int[] temp = new int[k];
        // int n=nums.length;
        // for(int i=0;i<k;i++){
        //     temp[i]=nums[(n-k)+i];
        // }
        // int t=nums[0];
        // for(int i=n-1;i>=k;i--){
        //     nums[i]=nums[i-k];
        // }
        // for(int i=0;i<temp.length;i++){
        //     nums[i]=temp[i];
        // }
        //optimised solution TC->O(2N) SC->O(1)
        int n = nums.length;
        k = k % n;
        reverse(nums, 0, n - k - 1);   // reverse first part
        reverse(nums, n - k, n - 1);   // reverse second part
        reverse(nums, 0, n - 1); 
    }
}
