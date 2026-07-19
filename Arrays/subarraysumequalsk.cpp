class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    //bruteforce method use loops TC-> O(N^3)
    //optimal solution TC -> O(N) SC-> O(N)
      unordered_map<int,int> map ;
      map[0]=1;
      int presum=0,cnt=0;
      for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int remove = presum-k;
        cnt+=map[remove];
        map[presum]+=1;
        }
    return cnt;
    }
};
