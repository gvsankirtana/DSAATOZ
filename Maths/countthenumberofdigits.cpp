class Solution {
public:
    int countDigit(int n) {
          //brute force method
          int cnt=0;
          while(n>0){
            n=n/10;
            cnt++;
          }
          return cnt;
          //optimised solution 
          return (int)(log(n));
    }
};
