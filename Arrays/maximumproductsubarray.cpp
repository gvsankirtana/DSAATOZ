class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute force solution use 3 loops TC->O(N^3) SC->O(1)
        //better solution use 2 loops TC->O(N^2) SC->O(1)
        //optimal solution TC->O(n) SC->O(1)
        int pre = 1,suff=1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre = pre*nums[i];
            suff = suff*nums[n-i-1];
            maxi = max(maxi,max(pre,suff));
        }
        return maxi;
    }
};
