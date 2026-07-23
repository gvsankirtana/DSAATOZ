class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //brute force solution is by using loops TC->O(N^3) SC->2xO(number of triplets)
        //better solution TC->O(N^2)xlog(size of set) SC->O(2N)+O(no. of triplets)
        set<vector<int>>st;
        for(int i=0;i<nums.size();i++){
            set<int>hashset;
            for(int j=i+1;j<nums.size();j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end()){
                    vector<int>temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        //optimal solution TC->O(N^2)+O(nlogn) SC->O(no. of unique triplets)
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1])j++;
                    while(j<k&&nums[k]==nums[k+1])k--;
                }
                }
            }
            return ans;
        }
};
