class Solution {
    //optimal solution time comlexity -> O(N) Space complexity O(1)
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                cnt++;
                if(maxi<cnt) maxi=cnt;
            }
            else{
                cnt=0;
            }
        }
        return maxi;
    }
}
