class Solution {
public:
//brute force is to loop O(N^2) SC->O(1)
//better solution use hashmap to record the count and do single iteration 
//TC->O(N) for unordered map SC->O(N)
//optimal solution TC->O(N) SC->O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0, el1=INT_MIN, el2=INT_MIN;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
      
        cnt1=0, cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(el1==nums[i]) cnt1++;
            if(el2==nums[i]) cnt2++;
        }
        
        int mini = (int)(nums.size()/3)+1;
        if(cnt1>=mini){
            ans.push_back(el1);
        }
        if(cnt2>=mini){
            ans.push_back(el2);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
