class Solution {
public:
//optimal solution kadane algorithms TC->O(N)
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        long long sum = 0;
        int start = -1;
        int astart=-1;
        int aend = -1;
        for(int i=0;i<nums.size();i++){
            if(sum==0){
              start=i;
            }
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
               astart = start;
               aend = i;
            }
            if(sum<0){
                sum=0;
            }
        }
        return astart,aend;

    }
};
