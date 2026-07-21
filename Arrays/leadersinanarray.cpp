class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      //brute force use loops TC->O(N^2) 
      //optimal solution TC->O(N)
      vector<int>ans;
      int maxi = INT_MIN;
      int n = nums.size();
      for(int i=n-1;i>=0;i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
        }
        maxi = max(maxi,nums[i]);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};
