class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        //brute force. use loops TC->O(N^3) sc->O(1)
        //better solution TC->O(N^2) SC->O(1)
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int xr=0;
            for(int j=0;j<nums.size();j++){
                xr=xr^nums[j];
            }
            if(xr==k)cnt++;
        }
        //optimised solution TC->O(N) SC->O(N)
        unordered_map<int,int>mpp;
        int xr=0,cnt=0;
        mpp[xr]++;
        for(int i=0;i<nums.size();i++){
            xr=xr^nums[i];
            int x = xr^k;
            cnt+=mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};
