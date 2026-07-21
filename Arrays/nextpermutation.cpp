class Solution {
public:
   //brute force approach find all permutations and store it TC->O(NxN!) SC->O(N)
   //better approach is to use the STL function next permutation for C++ library
   //optimal solution TC->O(N), SC->O(1)
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=ind;i--){
            if(nums[i]>nums[ind]){
                int temp = nums[i];
                nums[i]=nums[ind];
                nums[ind]=temp;
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};
