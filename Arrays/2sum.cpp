class Solution {
public:
//brute force TC->O(N^2) SC->O(1) using loops
//better solution TC->O(NlogN) SC-> O(N)
map<int,int> m;
       vector<int> v;
       for(int i=0;i<nums.size();i++)
       {
           if(m.find(target-nums[i])!=m.end())
           {
                v.push_back(m[target-nums[i]]);
                  v.push_back(i);
               return v;
           }
           m[nums[i]]=i;
       }
       return v;
//optimised solution TC-->O(N) SC->O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left=0,right=n-1;
        vector<pair<int,int>> val;
        for(int i=0;i<n;i++){
           val.emplace_back(nums[i],i);
        }
        sort(val.begin(),val.end());
        while(left<right){
            int sum = val[left].first+val[right].first;
            if(sum==target){
                return {val[left].second,val[right].second};
            }
            else if(sum<target)left++;
            else right--;
        }
        return {-1,-1};
    }
};
