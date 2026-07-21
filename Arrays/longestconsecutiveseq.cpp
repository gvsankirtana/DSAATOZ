class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute force solution use 2 loops and find if consecutive elements are present TC->O(N^2) SC->O(1)
        //better solution TC->O(nlogn) SC->O(1)
        // int cnt=0,lastsmaller=INT_MIN,longest=0;
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]-1==lastsmaller){
        //         cnt+=1;
        //         lastsmaller = nums[i];
        //     }
        //     else if(nums[i]!=lastsmaller){
        //         cnt=1;
        //         lastsmaller = nums[i];
        //     }
        //     longest = max(longest,cnt);
        // }
        // return longest;
        //optimal solution TC->O(N) SC->O(N)
        int n = nums.size();
        if(n==0)return 0;
        int longest=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
