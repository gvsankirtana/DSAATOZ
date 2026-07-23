class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //brute force use loops TC->O(N^4) SC->O(no.of quads)x2
        //better solution use hash TC->O(N^3)+O(log m) SC->O(no. of quads)x2 + O(n)
        // set<vector<int>> st;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         set<int>hashset;
        //         for(int k=j+1;k<n;k++){
        //             long long sum = 1LL * nums[i] + 1LL * nums[j] + 1LL * nums[k];
        //             long long fourth = 1LL * target - sum;
        //             if (fourth >= INT_MIN && fourth <= INT_MAX &&hashset.find((int)fourth) != hashset.end()) {
        //                  vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
        //                  sort(temp.begin(), temp.end());
        //                  st.insert(temp);
        //              }
        //             hashset.insert(nums[k]);
        //         }
        //     }
        // } 
        // vector<vector<int>> ans (st.begin(),st.end());
        // return ans;
        //optimal solution get rid of hashset TC->O(n^3) SC->O(no.of quads)
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=0;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int k=j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(nums[k]==nums[k-1])k++;
                        while(nums[l]==nums[l+1])l--;
                    }
                    else if(sum<target)k++;
                    else l--;
                }
            }
        }
       return ans;
    }
};
