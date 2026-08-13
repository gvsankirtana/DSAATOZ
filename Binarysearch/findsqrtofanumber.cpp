class Solution {
public:
    int floorSqrt(int n)  {
    //brute force using all number till n O(n)
    //optimal solution binary search O(log n)
      int low =0, high = n;
      while(low<=high){
        long long mid = (low+high)/2;
        long long val = mid*mid;
        if(val<=n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
      }
      return high;
    }
};
