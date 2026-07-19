class Solution {
    public int missingNumber(int[] nums) {
        //brute force use loop TC->O(N^2) SC->O(1)
        //better solution use hashing method TC->O(N) SC->O(N)
        //optimal solution TC->O(N) SC->O(1)
        int xor1=0,xor2=0;
        for(int i=0;i<nums.length-1;i++){
            xor2=xor2^nums[i];
            xor1=xor1^(i+1);
        }
        xor1=xor1^N;
        return xor1^xor2;
    }
}
