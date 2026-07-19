class Solution {
    public boolean check(int[] nums) {
      //brute force O(N^2)
      int n = nums.length;
    for (int i = 0; i < n; i++) {
        boolean isSorted = true;
        for (int j = 0; j < n - 1; j++) {
            int currentIdx = (i + j) % n;
            int nextIdx = (i + j + 1) % n;
            if (nums[currentIdx] > nums[nextIdx]) {
                isSorted = false;
                break; 
            }
        }
        if (isSorted) {
            return true;
        }
    }
    return false;
      //optimised solution O(N)
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(nums[(i+1)%nums.length]<nums[i]){
                cnt++;
            }
            if(cnt>1)return false;
        }
        return true;
    }
}
