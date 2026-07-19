class Solution {
    public int singleNumber(int[] nums) {
        //bruteforce using loops TC->O(N^2)
        //better approach using map ordered or unordered depens on data TC->O(N) SC->O(N)
        //Opitmal solution using xor
        int xor=0;
        for(int i=0;i<nums.length;i++){
            xor=xor^nums[i];
        }
        return xor;
    }
}
