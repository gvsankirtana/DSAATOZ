//O(log x) time, O(1) space
class Solution {
public:
    int reverse(int x) {
        long revnum=0;
        long y=abs(long(x));
        while(y>0){
            int ld=y%10;
            revnum=(revnum*10)+ld;
            y=y/10;
        }
        if(x<0){
            revnum = -revnum;
        }
        if (revnum > INT_MAX || revnum < INT_MIN) return 0;
        return (int)revnum;
    }
};
