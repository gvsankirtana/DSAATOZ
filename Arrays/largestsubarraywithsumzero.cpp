class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // Your code goes here
       //brute force solution O(N^3)
      //optimised solution O(N) using prefix sum
        unordered_map<int,int>mpp;
        int maxi=0,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi = max(maxi,i-mpp[sum]);
                }
                else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
