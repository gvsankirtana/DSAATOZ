class Solution {
    public int removeDuplicates(int[] nums) {
        //brute force TC->O(Nlogn) SC->O(n)
        // Set<Integer> st = new TreeSet<>();
        // for(int i=0;i<nums.length;i++){
        //     st.add(nums[i]);
        // }
        // int index=0;
        // for(int it:st){
        //     nums[index]=it;
        //     index++;
        // }
        // return index;
        //optimised 2 pointer approach TC->O(N) SC->O(1)
        int i=0;
        for(int j=1;j<nums.length;j++){
             if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
             }
        }
        return i+1;
    }
}
