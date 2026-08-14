class Solution {
public:
int finddays(vector<int>& weights,int cap){
    int days = 1, load = 0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>cap){
            days = days + 1;
            load = weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        //brute force O(sum-max)xO(n)
        //optimised solution O(log(sum-max+1))x O(n)
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int noofdays = finddays(weights,mid);
            if(noofdays<=days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
